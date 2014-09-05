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

typedef unsigned long long llu;
#define MOD 1000000007;

char ch[100005];
llu dp[100005][3][2];
int n;

llu find (int index, int less, int modval) {
  llu ans = dp[index][less][modval];

  if (ans != -1) return ans;
  else {
    ans = 0;
    if (index == n) {
      if (less == 0 && modval == 0) ans = 1;
      else ans = 0;
    }
    else {
      if (less > 0) {
        for (int i = 0; i <= ch[index] - '0'; i++) {
          if (i == ch[index] - '0') {
            ans += find(index+1,1,(modval+i*i)%3);
            ans %= MOD;
          }
          else {
            ans += find(index+1,0,(modval+i*i)%3);
            ans %= MOD;
          }
        }
      }
      else if (less == 0){
        for (int i = 0; i <= 9; i++) {
          ans += find(index+1,0,(modval+i*i)%3);
          ans %= MOD;
        }
      }
    }
    return ans;
  }
}

int main () {
  int t;
  inp(t);

  while (t--) {
    scanf("%s",&ch);
    n = strlen(ch);
    memset(dp,-1,sizeof(dp));
    llu ans = find(0,1,0);
    printf("%llu\n",ans);
  }
}