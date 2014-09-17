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

#define N 30009

struct node {
  int open, close;
  node():close(0),open(0){}
  void init (char s) {
    if (s == '(') open = 1, close = 0;
    else close = 1, open = 0;
  }
  void merge (const node &l,const node &r) {
    int mi = min(l.open, r.close);
    open = l.open - mi + r.open;
    close = l.close + r.close - mi;
  }
}tree[4*N];


char arr[N];

void build_tree(int node, int a, int b) {
  if(a > b) return;
    
  if(a == b) { 
    tree[node].init(arr[a]);
    return;
  }

  build_tree(node*2, a, (a+b)/2);
  build_tree(node*2+1, 1+(a+b)/2, b);
  tree[node].merge(tree[node*2], tree[node*2+1]);
}


void update(int node, int s, int e, int pos) {
    if (s == e) {
        if (arr[s] == '(') arr[s] = ')';
        else arr[s] = '(';
        tree[node].init(arr[s]);
        return;
    }
    int mid = (s + e)/2;
    if (pos >= s && pos <= mid) update(node*2, s, mid, pos);
    else update(node*2+1, mid+1, e, pos);
    tree[node].merge(tree[node*2], tree[node*2+1]);
}

// void print_tree () {
//   int last = 1<<(x+2) - 1;
//   for (int i = 1; i < last; i++) {
//     printf("%d %d\n",tree[i].open, tree[i].close);
//   }
// }


int main () {

  for (int i = 0; i < 10; i++) {
    int n, m; 
    inp(n);
    scanf("%s",arr);

    build_tree(1,0,n-1);
    
    inp(m);
    printf("Test %d:\n", i+1);
    for (int i = 0; i < m; i++) {
      int x; inp(x);
      if (x != 0) {
        update(1,0,n-1,x-1);
        // print_tree();
      }
      else if (tree[1].open == 0 && tree[1].close == 0) printf("YES\n");
      else printf("NO\n"); 
    }
  }
}
