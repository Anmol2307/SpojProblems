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
#include <climits>

using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000
#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define EPS 1e-9
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)


typedef long long int LL;

string inttostring(int n)
{
  stringstream a;
  a<<n;
  string A;
  a>>A;
  return A;
}

int stringtoint(string A)
{
  stringstream a;
  a<<A;
  int p;
  a>>p;
  return p;
}

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

///////////////////////////////////////////////////////////////////////////////////////////
int A[100001]={0};
int n = 100000;

struct node {
  int count[10];
};

node tree[500003];

node makeNode(int * value) {
  struct node n;
  for (int i = 0; i < 10; i++) {
    n.count[i] = value[i];
  }
  return n;
}

node combineNode(node l, node r) {
    int val[10];
    for (int i = 0; i < 10; i++) {
      val[i] = l.count[i] + r.count[i];
    }
    return makeNode(val);
}

void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
    
    if(a == b) { // Leaf node
      if(A[a]!=-1) {
        string str = inttostring(a);
        int val[10];
        for (int i = 0; i < 10; i++) {
          if (str.find((char)(i+48)) != string::npos) {
            val[i] = 1; // Init value
          }
          else {
            val[i] = 0; // Init value
          }
        }
        // if (a == 1 || a == 2) printf("%d\n",node);
        // exit(0);
        tree[node] = makeNode(val);

      }
      return;
    }
  
  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
  
  tree[node] = combineNode(tree[node*2], tree[node*2+1]); // Init root value
}
 
node query_tree(int node, int a, int b, int i, int j) {
  
  if (a==i && b==j) {
    for (int i = 0; i < 10; i++) {
      // printf("%d %d\n",i,tree[node].count[i]);
    }
    return tree[node];
  }
  int mid = (a+b)/2;
    if (j <= mid) {
        // printf("HERE %d %d %d %d %d\n",node<<1,a,mid,i,j);
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    struct node l = query_tree((node<<1), a, mid, i, mid);
    struct node r = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
    // printf("HERE %d\n",node);
    return combineNode(l,r);

}

void nosq()
{
 int i,k,j;
 for(i=2;i<=320;i++)
 {
  if(A[i]==0)
  {
   k=i*i;
   for(j=k;j<=100000;j+=k)
    A[j]=-1;
  }
 }
 k=1;
 for(i=1;i<=100000;i++)
  if(A[i]==0)
   A[i]=k++;
}

int main()
{
 nosq();
 int t,a,b;
 char d;
 inp(t); 
 build_tree(1,1,n);
 // for (int i = 0; i < 10; i++) {
 //    printf("%d %d\n",i,tree[65536].count[i]);
 //  }
 //  printf("\n");
 //  for (int i = 0; i < 10; i++) {
 //    printf("%d %d\n",i,tree[131072].count[i]);
 //  }
 //  printf("\n"); 
 //  for (int i = 0; i < 10; i++) {
 //    printf("%d %d\n",i,tree[131073].count[i]);
 //  }
 for(int i=1;i<=t;i++)
 {
  scanf("%d %d %c",&a,&b,&d);
  struct node y = query_tree(1, 1, n, a, b);
  printf("%d\n",y.count[d-'0']);
 }
 return 0;
}