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
inline int max2(int a, int b) {
	return ((a > b)? a : b);
}

inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}


long long arr[N];
long long tree[200007];
long long lazy[200007];

 
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    	tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = tree[node*2] + tree[node*2+1]; // Init root value
}
 
/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j) {
    

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a == b) { // Leaf node
    		tree[node] = sqrt(tree[node]);
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child
 
	tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}

void update_tree_lazy(int node, int a, int b, int i, int j) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it
 
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    		lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
 
   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    long long value = sqrt(tree[node]);
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] = value;
 
		if(a != b) { // Not leaf node
			lazy[node*2] = value;
			lazy[node*2+1] = value;
		}
 
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child
 
	tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}
 
/**
 * Query tree to get max element value within range [i, j]
 */
long long query_tree(int node, int a, int b, int i, int j) {
	
	if (a==i && b==j) return tree[node];
	int mid = (a+b)/2;
    if (j <= mid) {
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    long long l = query_tree((node<<1), a, mid, i, mid);
    long long r = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
    return l+r;

}

long long query_tree_lazy(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range
 
	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it
 
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
 
		lazy[node] = 0; // Reset it
	}
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int mid = (a+b)/2;
    if (j <= mid) {
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    long long l = query_tree((node<<1), a, mid, i, mid);
    long long r = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
    return l+r;
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
	
	int x = 1;
	while (scanf("%d",&n) == 1) {

		for(int i = 0; i < n; i++) {
			scanf("%lli",&arr[i]);
		}
	 
		build_tree(1, 0, n-1);
	 	int m;
	 	inp(m);
	 	printf("Case #%d:\n",x);
		for (int i=0; i < m; i++) {
	 		int t,x, y;
	 		inp(t);inp(x);inp(y);
	 		x--,y--;
	 		if(x > y) swap(x, y);
	 		if (t==0) update_tree_lazy(1,0,n-1,x,y);
	 		else printf("%lli\n",query_tree_lazy(1, 0, n-1, x, y));
	 	}
	 	printf("\n");
	 	x++;
 	}
}