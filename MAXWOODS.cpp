#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

typedef long long int lli;

vector <vector<char> > mat;
int dp[201][201];
int m, n;
// 0 for right and 1 for left

bool check (int i, int j) {
  if (i >= m || i < 0 || j >= n || j < 0 || mat[i][j] == '#') return false;
  return true;
}

int find (int i, int j, int dir) {
  if (!check(i,j)) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  int ans = 0;
  if (mat[i][j] == 'T') {
    ans++;
  }
  int x, y;
  if (dir == 0) {
    x = max(find(i,j+1,0),find(i+1,j,1));
    ans += x;
  }
  else if (dir == 1) {
    y = max(find(i,j-1,1),find(i+1,j,0));
    ans += y;
  }
  dp[i][j] = ans;
  return ans;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    inp(m); inp(n);
    mat.clear();
    memset(dp,-1,sizeof(dp));
    
    for (int i = 0; i < m; i++) {
      char ch[200];
      scanf("%s\n",ch);
      int len = strlen(ch);
      vector <char> vec;
      for (int j = 0; j < len; j++) {
        vec.push_back(ch[j]);
      }
      mat.push_back(vec);
    }
    int ans = find(0,0,0);
    printf("%d\n",ans);
  }
}