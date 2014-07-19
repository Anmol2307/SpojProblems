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

  int n;
  while (scanf("%d",&n) == 1) {
    int arr[n];
    for (int i=0; i < n; i++) {
      scanf("%d",&arr[i]);
    }
    int dp[n][n];
    int cdp[n][n];

    for (int i=0; i<n; i++) {
      dp[i][i]=arr[i];
      cdp[i][i]=0;
    }

    for (int l =2; l <= n; l++) {
      // printf("%s\n","HERE");
      for (int i = 0; i < n-l+1; i++) {
        int j = i+l-1;
        cdp[i][j] = INT_MAX;
        for (int k =i; k <= j-1; k++) {
          int cost = dp[i][k]*dp[k+1][j];
          // printf("%d %d %d\n",i,k,j);
          if ((cost + cdp[k+1][j] + cdp[i][k]) < cdp[i][j]) {
            dp[i][j] = (dp[i][k] + dp[k+1][j])%100;
            cdp[i][j] = cost + cdp[k+1][j] + cdp[i][k];
            // printf("HERE %d\n",cdp[i][j]);
          }
        }
      }
    }
    printf("%d\n",cdp[0][n-1]);
  }

}