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

///////////////////////////////////////////////////////////////////////////////////////////


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool visited[105][105];
int matrix[105][105];
int level[105][105];
int n, m; 

bool valid (int x, int y) {
  return x >=0 && x < n && y >= 0 && y < m;
}

void dfs (int x, int y, int h) {
  visited[x][y] = 1;
  level[x][y] = matrix[x][y];

  f(i,0,4){
    int X = x + dx[i];
    int Y = y + dy[i];
    if (valid(X,Y)) {
      if (h <= matrix[X][Y]) {
        if (!visited[X][Y]) {
          dfs(X,Y,matrix[X][Y]);
        }
      }
    }
  }
}


int main () {

  int t;
  cin>>t;

  while (t--) {
    cin >> n >> m;
    f(i,0,n){
      f(j,0,m){
        cin>>matrix[i][j];
        level[i][j] = 100000;
      }
    }
    FILL(visited,0);

    f(i,0,m) {
      if (!visited[0][i]){
        dfs(0,i,matrix[0][i]);
      }
      if (!visited[n-1][i]){
        dfs(n-1,i,matrix[n-1][i]);
      }
    }

    f(i,0,n) {
      if (!visited[i][0]){
        dfs(i,0,matrix[i][0]);
      }
      if (!visited[i][m-1]){
        dfs(i,m-1,matrix[i][m-1]);
      }
    }
    while (1) {
      bool flag = true;
      f(i,1,n-1){
        f(j,1,m-1){
          int val = 100000;
          if (!visited[i][j]) {
            f(k,0,4) {
              int X = i + dx[k];
              int Y = j + dy[k];
              val = min(val,max(matrix[X][Y],level[X][Y]));
            }
            if (val < level[i][j]) {
              level[i][j] = val;
              flag = false;
            }
          }
        }
      }
      if (flag) break;
    }
    int ans = 0;
   
    f(i,0,n){
      f(j,0,m){
        if (level[i][j] > matrix[i][j]){
          ans += level[i][j] - matrix[i][j];
        }
      }
    }
    cout << ans << endl;
  } 

}