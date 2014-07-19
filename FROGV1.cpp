/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */
 
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <fstream>
#include <utility>
#include <iomanip>

using namespace std;
 
#define N 100003
#define MAX (10+(1<<6)) // Why? :D
#define inf 0x7fffffff
 


struct node {
	long long min;
	long long max;
};
int k;


int arr[N];
int brr[N];
node tree[200007];
 

node makeNode(long long min, long long max) {
	node n;
	n.min = min;
	n.max = max;
	return n;
}

node combineNode(node l, node r) {
	if (l.max >= r.min) return makeNode(l.min, r.max);
	else return makeNode(l.min,l.max);
    
}

void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    	tree[node] = makeNode(brr[a],brr[a]+k); // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = combineNode(tree[node*2], tree[node*2+1]); // Init root value
}
node query_tree(int node, int a, int b, int i, int j) {

	if (a==i && b==j) {
		return tree[node];
	}
	int mid = (a+b)/2;
    if (j <= mid) {
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    struct node l = query_tree((node<<1), a, mid, i, mid);
    struct node r = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
    return combineNode(l,r);

}

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}
 
int binarySearch(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] >= key )
            r = m;
        else
            l = m;
    }
 
    return r;
}

int main() {
	int n,p;
	inp(n);inp(k);inp(p);
	
	for(int i = 0; i < n; i++) {
		inp(arr[i]);
		brr[i]=arr[i];
	}
	sort(brr,brr+n);
 	
	build_tree(1, 0, n-1);

	for (int i=0; i < p; i++) {
 		int x, y;
 		inp(x);inp(y);
 		x = binarySearch(brr,-1,n-1,arr[x-1]);
    	y = binarySearch(brr,-1,n-1,arr[y-1]);
    	if(x > y) swap(x, y);
 		node n1 = query_tree(1, 0, n-1, x, y);
 		if (brr[x] <= n1.max && brr[x] >= n1.min && brr[y] <= n1.max && brr[y] >= n1.min) printf("%s\n","Yes");
 		else printf("%s\n","No");
 	}
}