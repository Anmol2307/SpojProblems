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
inline int max2(int a, int b) {
	return ((a > b)? a : b);
}

inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}


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
void update_tree(int node, int a, int b, int i, int value) {
    

	if(a==b && b==i) {
		tree[node].best = tree[node].sum = tree[node].left = tree[node].right = arr[i] = value;
		return;
	}
	int m = (a+b)/2;
	if(i<=m) update_tree(2*node, a, m, i, value);
	else update_tree(2*node+1, m+1, b, i, value);
	tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;
	tree[node].best = max3(tree[2*node].best, tree[2*node].right + tree[2*node+1].left, tree[2*node+1].best);
	tree[node].left = max2(tree[2*node].left, tree[2*node].sum + tree[2*node+1].left);
	tree[node].right = max2(tree[2*node].right + tree[2*node+1].sum, tree[2*node+1].right);
}
 
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
 		int t,x, y;
 		inp(t);inp(x);inp(y);
 		if (t==0) update_tree(1,0,n-1,x-1,y);
 		else printf("%li\n",query_tree(1, 0, n-1, x-1, y-1).best);
 	}
}