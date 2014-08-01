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



int main () {

  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    pair<int,int> arr[n];
    long long cost[n];
    long long dp[n];
    int ideal;
    long long sum[n];
    
    for (int i = 0; i < n; i++) {
      inp(arr[i].first);
    }
    inp(arr[0].second);
    sum[0] = arr[0].second;
    for (int i = 1; i < n; i++) {
      inp(arr[i].second);
      sum[i] = sum[i-1] + arr[i].second;
    }

    sort(arr,arr+n);
    
    cost[0] = 0;
    for (int i = 1; i < n; i++) {
      cost[i] = cost[i-1] + (long long)((long long)sum[i-1]*(long long)(arr[i].first-arr[i-1].first));
    }

    ideal = arr[0].first;
    for (int i = 1; i < n; i++) {
      long long val = cost[i];
      int x = abs(arr[i].first-ideal);
      if (val < cost[i-1] + (long long)((long long)x*(long long)arr[i].second)) {
        ideal = arr[i].first;
      } 
      else {
        val = cost[i-1] + (long long)((long long)x*(long long)arr[i].second);
      }
      dp[i] = val;
    }
    printf("%lli\n",dp[n-1]);
  }

}