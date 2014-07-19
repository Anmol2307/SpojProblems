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


typedef long long int lli;

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

lli gcd(lli a, lli b) 
{
    lli t;
    while (b) 
    {
        t = a;
        a = b;    
        b = t%b;   
    }
    return a;
}
lli mod_of_lcm(lli a[],lli n)
{
    lli ans=1;
    for(lli i=0;i<n;i++)
    {
        if(a[i]!=1)
        {
            for(lli j=i+1;j<n;j++)
            {
                a[j]/=gcd(a[i],a[j]);
                //reducing all remaining numbers by thier gcd with currebt number
            }
            ans=(ans*a[i])%mod;//mod
        }
    }
    return ans;
}


int main () {
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    int arr[n+1];
    int mark[n+1];
    lli a[n+1];
    for (int i=1; i <= n; i++) {
      inp(arr[i]);
      mark[i]=0;
    }
    // LL lcm = 1;
    lli ans = 1;
    int y = 0;
    for (int i = 1; i <=n;i++) {
      if (!mark[i]) {
        lli x = 0;
        while (!mark[i]) {
          mark[i]=1;
          i=arr[i];
          x++;
        }
        a[y] = x;
        y++;
        // lcm = (LL)x*(LL)((LL)lcm/(LL)gcd(x,lcm));
        // lcm = ((x%mod)*((lcm/gcd(x,lcm))%mod))%mod;
      }
    }
    ans = mod_of_lcm(a,y);
    printf("%lli\n",ans);
  }
}