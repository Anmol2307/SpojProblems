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

///////////////////////////////////////////////////////////////////////////////////////////

 

int main () {

  int t;
  scanf("%d",&t);

  while (t--) {
    int o,n;
    scanf("%d",&o);scanf("%d",&n);

    int m;
    scanf("%d",&m);

    int oarr[m];
    int narr[m];
    int warr[m];

    for (int i = 0; i < m; i++) {
      scanf("%d",&oarr[i]);
      scanf("%d",&narr[i]);
      scanf("%d",&warr[i]);
    }
    int dp[m+1][o+1][n+1];
    // memset(dp,INF,sizeof(dp));
    // cout << dp[0][0][1] << endl;
    // exit(0);
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= o; j++) {
        for (int k = 0; k <= n; k++) {
          if (i==0) {
            if (j==0 && k == 0) dp[i][j][k] = 0;
            else dp[i][j][k] = INF;
          }
          else if (j==0 && k== 0) dp[i][j][k] = 0;
          else if (j==0 && k != 0) {
            if (narr[i-1] <= k) dp[i][j][k] = min(warr[i-1] + dp[i-1][j][k-narr[i-1]], dp[i-1][j][k]);
            else dp[i][j][k] = min(warr[i-1] + dp[i-1][j][0], dp[i-1][j][k]);
          }
          else if (k==0 && j != 0) {
            if (oarr[i-1] <= j) dp[i][j][k] = min(warr[i-1] + dp[i-1][j-oarr[i-1]][k], dp[i-1][j][k]);
            else dp[i][j][k] = min(warr[i-1] + dp[i-1][0][k], dp[i-1][j][k]);
          }
          else if (oarr[i-1] <= j && narr[i-1] <= k) {
            dp[i][j][k] = min(warr[i-1] + dp[i-1][j-oarr[i-1]][k-narr[i-1]], dp[i-1][j][k]);
          }
          else if (oarr[i-1] > j && narr[i-1] <= k) {
            dp[i][j][k] = min(warr[i-1] + dp[i-1][0][k-narr[i-1]], dp[i-1][j][k]);
          }
          else if (oarr[i-1] <= j && narr[i-1] > k) {
            dp[i][j][k] = min(warr[i-1] + dp[i-1][j-oarr[i-1]][0], dp[i-1][j][k]);
          }
          else {
            dp[i][j][k] = min(warr[i-1] + dp[i-1][0][0], dp[i-1][j][k]);
          }
        }
      }
    }

    printf("%d\n",dp[m][o][n]);

  }
}