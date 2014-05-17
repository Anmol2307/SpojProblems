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
bool visited[30][30];
int matrix[30][30];
char cost[30][30];
int w, h; 

bool valid (int x, int y) {
  return x >=0 && x < h && y >= 0 && y < w && cost[x][y] != 'X';
}
void print_matrix () {
  f(i,0,h) {
      f(j,0,w) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
}


void dfs (int x, int y, int c) {
  visited[x][y] = 1;


  f(i,0,4){
    int X = x + dx[i];
    int Y = y + dy[i];
    if (valid(X,Y)) {
      //if (h <= matrix[X][Y]) {
        if (!visited[X][Y]) {
          matrix[X][Y] = c + (int)(cost[X][Y]-48);
          // cout << "X = " << x << " Y = " << y << " I = " << i << endl << endl;
          // print_matrix();
          // cout << endl << endl;
          if (cost[X][Y] != 'D') dfs(X,Y,c + (int)(cost[X][Y]-48));  
        }
        else {
          if (matrix[X][Y] != -1 && matrix[X][Y] > (c + (int)(cost[X][Y]-48))) {
            matrix[X][Y] = c + (int)(cost[X][Y]-48);
            // cout << "X = " << x << " Y = " << y << " I = " << i << endl << endl;
            // print_matrix();
            // cout << endl << endl;
            if (cost[X][Y] != 'D') dfs(X,Y,c + (int)(cost[X][Y]-48));  
          }
        }
      //}
    }

  }
}


int main () {

  while (cin >> w >> h && w != 0 && h != 0) {
    int sx, sy, dx, dy;

    f(i,0,h) {
      f(j,0,w) {
        cin >> cost[i][j];
        if (cost[i][j] == 'S') {
          sx = i; sy = j;

        }
        else if (cost[i][j] == 'D') {
          dx = i; dy = j;
          cost[i][j] = '0';
        }
      }
    }

    FILL(visited,0);
    FILL(matrix,-1);
    
    dfs(sx,sy,0);
    //print_matrix();
    cout << matrix[dx][dy] << endl;
  }


}
