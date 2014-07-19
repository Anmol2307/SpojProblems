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
 
#define N 50003
#define MAX (10+(1<<6)) // Why? :D
#define inf 0x7fffffff
 


struct node {
	long sum;
	long best;
	long left;
	long right;
};


int arr[N];
node tree[200003];
 

node makeNode(long s, long b, long l,long r) {
	node n;
	n.sum = s;
	n.best = b;
	n.left = l;
	n.right = r;
	return n;
}

node combineNode(node l, node r) {
	long left = l.left;
    if (l.sum + r.left>left) left =l.sum + r.left;
    long right = r.right;
    if (r.sum + l.right > right) right = r.sum + l.right;
    long best = max(l.right + r.left, max(l.best, r.best));
    return makeNode(l.sum+r.sum,best, left, right);
}
/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    	tree[node] = makeNode(arr[a],arr[a],arr[a],arr[a]); // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = combineNode(tree[node*2], tree[node*2+1]); // Init root value
}
 
/**
 * Increment elements within range [i, j] with value value
 */
// void update_tree(int node, int a, int b, int i, int j, int value) {
    
// 	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
// 		return;
    
//   	if(a == b) { // Leaf node
//     		tree[node] += value;
//     		return;
// 	}
 
// 	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
// 	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
// 	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
// }
 
/**
 * Query tree to get max element value within range [i, j]
 */
node query_tree(int node, int a, int b, int i, int j) {
	
	if (a==i && b==j) return tree[node];
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
 
int main() {
	int n;
	inp(n);

	for(int i = 0; i < n; i++) {
		inp(arr[i]);
	}
 
	build_tree(1, 0, n-1);
 	int m;
 	inp(m);

	for (int i=0; i < m; i++) {
 		int x, y;
 		inp(x);inp(y);
 		printf("%li\n",query_tree(1, 0, n-1, x-1, y-1).best);
 	}
}