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

int dp[2][5005]; 
char ch[5005];
  
int main () {
  int n;
  inp(n);
  scanf("%s\n",ch);
  
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      if (ch[i] == ch[j]) {
        dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
      } else {
        dp[i % 2][j] = 1 + min(dp[i % 2][j - 1], dp[(i + 1) % 2][j]);
      }
    }
  }
  printf("%d\n",dp[0][n-1]);
}