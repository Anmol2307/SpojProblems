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

#define N 100000

struct node {
  int val;
  node():val(0){}
  void init (int s) {
    val = s;
  }
  void merge (node &l, node &r) {
    val = l.val + r.val;
  }
}tree[4*N + 10];;

int arr[N+5];
int n, x;

void build_tree(int node, int a, int b) {
  if(a > b) return;
    
  if(a == b) { 
    tree[node].init(arr[a]);
    return;
  }

  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
  tree[node].merge(tree[node*2], tree[node*2+1]);
}


void update_tree(int node, int a, int b, int i, int j, int value) {
    
 if(a > b || a > j || b < i)
   return;
    
    if(a == b) {
      arr[a] += value;
      tree[node].init(arr[a]);
      return;
    }
 
 update_tree(node*2, a, (a+b)/2, i, j, value);
 update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
 
 tree[node].merge(tree[node*2], tree[node*2+1]);
}

int query_tree(int node, int a, int b, int i, int j) {
  
  if (a==i && b==j) return tree[node].val;
  int mid = (a+b)/2;
    if (j <= mid) {
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    int left = query_tree((node<<1), a, mid, i, mid);
    int right = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
    return left + right;
}



// void print_tree () {
//   int last = 1<<(x+2) - 1;
//   for (int i = 1; i < last; i++) {
//     printf("%d %d\n",tree[i].open, tree[i].close);
//   }
// }


int main () {

  int t;
  inp(t);

  while (t--) {
    memset(arr,0,sizeof(arr));
    memset(tree,0,sizeof(tree));

    int n, c;
    inp(n); inp(c);

    for (int i = 0; i < c; i++) {
      int type;
      inp(type);

      if (type == 0) {
        int p, q, v;
        inp(p); inp(q); inp(v);
        update_tree(1,0,n-1,p-1,q-1,v);
      }
      else {
        int p, q;
        inp(p); inp(q);
        printf("%d\n",query_tree(1,0,n-1,p-1,q-1));
      }
    }
  }
}