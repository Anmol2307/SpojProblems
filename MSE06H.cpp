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
#define i64 unsigned long long

typedef long long LL;

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

//////////////////////////////////////////////////////////////////////////////////  
long long tree[1000001];
int n;

void update(int idx ,int val){
  while (idx <= n){
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

long long read(int idx){
  long long sum = 0; // sum will be decreased
  while (idx > 0) {
    sum+=tree[idx];
    idx-=idx&(-idx);
  }
  return sum;
}


int main () {

  int t;
  inp(t);
  int x = 1;
  while (t--) {
    memset(tree,0,sizeof(tree));
    int m,k;
    inp(n);inp(m);inp(k);

    pair<int,int> a[k+1];

    for (int i=1;i<=k;i++) {
      inp(a[i].first);
      inp(a[i].second);
    }

    sort(a+1,a+k+1);
    long long ans = 0;
    for (int i=k;i>=1;i--) {
      int j;
      for (j=i; j>=1 && a[j].first==a[i].first;j--) {
        ans+=read(a[j].second-1);
        // for (int i=1;i<=k;i++) {
        //   printf("R %d %d %d\n",a[i].first,a[i].second,tree[i]);
        // }
        // printf("\n");
      }
      for (j=i; j>=1 && a[j].first==a[i].first;j--) {
        update(a[j].second,1);
        // 
      }
      i=j+1;
    }

    printf("Test case %d: %lli\n",x,ans);
    x++;

  }


}