#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

#define N 100005
#define inf 0x7fffffff

int tree[4*N];;
int arr[N];
int lazy[4*N];
int n, x;

void build_tree(int node, int a, int b) {
  if(a > b) return;
    
  if(a == b) { 
    tree[node] = arr[a];
    return;
  }

  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
  tree[node] = tree[node*2] +  tree[node*2+1];
}


void update_tree(int node, int a, int b, int i, int j, int value) {
  
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
    
    if(a >= i && b <= j) { // Segment is fully within range
        tree[node] += value;
 
      if(a != b) { // Not leaf node
        lazy[node*2] += value;
        lazy[node*2+1] += value;
      }
   
      return;
    }
 
    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
   
    tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}

int query_tree(int node, int a, int b, int i, int j) {
  
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
 
  int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
  int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
  int res = q1 + q2; // Return final result
  
  return res;
}

void print_tree () {
  int last = 16;
  for (int i = 1; i < last; i++) {
    printf("%d ",tree[i]);
  }
  printf("\n");
}


int main () {

  int t;
  inp(t);

  while (t--) {
    memset(arr,0,sizeof(arr));
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));

    int n, c;
    inp(n); inp(c);

    for (int i = 0; i < c; i++) {
      int type;
      inp(type);

      if (type == 0) {
        int p, q, v;
        inp(p); inp(q); inp(v);
        update_tree(1,0,n-1,p-1,q-1,v);
        print_tree();
        // exit(0);
      }
      else {
        int p, q;
        inp(p); inp(q);
        printf("%d\n",query_tree(1,0,n-1,p-1,q-1));
      }
    }
  }
}