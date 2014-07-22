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
#define mod 1000000000
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
#define REP(i,n) for (int i = 1; i <= n; i++)


typedef long long int ll;
typedef vector<vector<ll> > matrix;

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
int k;
int prime;

matrix mul(matrix A, matrix B)
{
    matrix C(k+2, vector<ll>(k+2));
    REP(i, k+1) REP(j, k+1) REP(m, k+1)
        C[i][j] = (C[i][j] + A[i][m] * B[m][j]) % prime;
    return C;
}

// computes A ^ p
matrix pow(matrix A, ll p)
{
    // printf("HER %lli\n",p);
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);

    return mul(X, X);
}



int main () {

  int t;
  inp(t);

  while (t--) {
    
    inp(k);

    int b[k+1];
    int c[k+1];
    vector<ll> F1(k+2);
    matrix T(k+2,vector<ll>(k+2));

    F1[1]=0;
    for (int i=2; i <= k+1; i++) {
      inp(b[i-1]);
      F1[i] = b[i-1];
    } 

    T[1][1] = 1;
    for (int i=1; i <= k; i++) {
      inp(c[i]);
      T[k+1][k+2-i]= c[i];
    }
    T[k+1][1] = 0;

    for (int i =1; i <= k; i++) {
      T[i][i+1] = 1;
    }

    ll m,n;

    scanf("%lli %lli %d",&m,&n,&prime);

      

      matrix T2(k+2,vector<ll>(k+2));
      T2 = pow(T, m-1);
      ll sm=0;
      for (int i=1; i <= k+1; i++) {
          sm = (sm + (ll)(T2[1][i] * F1[i])) % prime;
      }

      T = pow(T, n);
      ll sn=0;
      for (int i=1; i <= k+1; i++) {
          sn = (sn + (ll)(T[1][i] * F1[i])) % prime;
      }
      ll ans = (sn - sm)%prime;
      if (ans > 0 ) printf("%lli\n",ans);
      else {
        int i =1;

        while (prime*i+ans < 0) {
          i++;
        }
        printf("%lli\n", (prime*i + ans) );
      }
    // }
  }
}