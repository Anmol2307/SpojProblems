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

struct node
{
        int numleaves, add, sum;
        node():numleaves(0),add(0),sum(0){}
        void split(node& l, node& r)
        {
                l.add += add;
                l.sum += add * l.numleaves;
                r.add += add;
                r.sum += add * r.numleaves;
                add=0;
        }
        void merge(node& l, node& r)
        {
                numleaves = l.numleaves + r.numleaves;
                add = 0;
                sum = l.sum + r.sum;
        }
}tree[4*N];

void update_single_node(node& n, int inc){
        n.add += inc;
        n.sum += inc * n.numleaves;
}

void print_tree () {
  int last = 16;
  for (int i = 1; i < last; i++) {
    printf("%d %d\n",tree[i].add, tree[i].sum);
  }
}

void range_update(int root, int left_most_leaf, int right_most_leaf, int u, int v, int new_val)
{
  if(u<=left_most_leaf && right_most_leaf<=v)
    return update_single_node(tree[root], new_val);
  
  int mid = (left_most_leaf+right_most_leaf)/2,
  left_child = root*2,
  right_child = left_child+1;

  tree[root].split(tree[left_child], tree[right_child]);
  if(u <= mid) range_update(left_child, left_most_leaf, mid, u, v, new_val);
  if(v > mid) range_update(right_child, mid+1, right_most_leaf, u, v, new_val);
  tree[root].merge(tree[left_child], tree[right_child]);
}

node range_query(int root, int left_most_leaf, int right_most_leaf, int u, int v)
{
  //query the interval [u,v), ie, {x:u<=x<v}
  //the interval [left_most_leaf,right_most_leaf) is 
  //the set of all leaves descending from "root"
  if(u<=left_most_leaf && right_most_leaf<=v){
    printf("I came here %d %d %d\n",root,tree[root].sum, tree[root].add);
    return tree[root];
  }
  int mid = (left_most_leaf+right_most_leaf)/2, 
  left_child = root*2, 
  right_child = left_child+1;
  tree[root].split(tree[left_child], tree[right_child]);
  printf("HERE %d %d %d\n",root,u,v);
  print_tree();
  node l, r;
  //identity is an element such that merge(x,identity) = merge(identity,x) = x for all x
  if(u <= mid) l = range_query(left_child, left_most_leaf, mid, u, v);
  if(v > mid) r = range_query(right_child, mid+1, right_most_leaf, u, v);
  tree[root].merge(tree[left_child],tree[right_child]);
  node n;
  n.merge(l,r);
  return n;
}



int main () {

  int t;
  inp(t);

  while (t--) {
    int n, c;
    inp(n); inp(c);

    for (int i = 0; i < c; i++) {
      int type;
      inp(type);

      if (type == 0) {
        int p, q, v;
        inp(p); inp(q); inp(v);
        range_update(1,0,n-1,p-1,q-1,v);
        print_tree();
        // exit(0);
      }
      else {
        int p, q;
        inp(p); inp(q);
        struct node nod = range_query(1,0,n-1,p-1,q-1);
        printf("I came here %d %d %d\n",root,tree[root].sum, tree[root].add);
        printf("%d\n",nod.add);
      }
    }
  }
}