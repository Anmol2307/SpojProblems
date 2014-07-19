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


int main () {

  int t,n,m;
  inp(t);

  while (t--) {
    inp(n);inp(m);
    int p[n][m];
    for (int i=0;i<n;i++) {
      int x=i;
      int count=m;
      int j = 0;
      int val;
      inp(val);
      while (count--) {
        if (x<0) x=n-1;
        p[x][j]=val;
        x--;j++;
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j< m; j++) {
    //     printf("%d ",p[i][j]);
    //   }
    //   printf("\n");
    // }
    // cout << p[0][0] << endl;
    // exit(0);

    int ans[n][m];
    int pro = n*m;
    int y = 1;
    int a[pro];
    memset(a,0,sizeof(a));
    bool flag = false;
    for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
        int value;
        if (p[j][i] != 0) {
          value = n*i+p[j][i];
        }
        else {
          value = n*(i+1);
        }
        if (a[value-1] == 0 && value >= 1 && value <= pro && n > 1) ans[j][i] = value;
        else {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j< m-1; j++) {
          printf("%d ",ans[i][j]);
        }
        printf("%d\n",ans[i][m-1]);
      }
    }
    else {
      printf("%s\n","No Solution");   
    }

  }


} 