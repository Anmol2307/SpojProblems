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



int main () {
  int t;
  inp(t);
  int cases = 1;
    
  while (t--) {
    int N, K, B, T;
    inp(N); inp(K); inp(B); inp(T);
    int A[N];
    int S[N];
    bool WillReach[N];
    memset(WillReach,false,sizeof(WillReach));
    for (int i = 0; i < N; i++) {
      inp(A[i]);
    }
    int finishers = 0;
    for (int i = 0; i < N; i++) {
      inp(S[i]);
      if ((A[i] + S[i]*T) >= B) {
        finishers++;
        WillReach[i] = true;
      }
    }
    if (finishers < K) printf("Case #%d: IMPOSSIBLE\n",cases);
    else {
      int x = 0;
      int swaps = 0;
      int ans = 0;
      for (int i = N-1; i >= 0; i--) {
        if (WillReach[i]) {
          x++;
          ans += swaps;
          if (x == K) break;
        }
        else swaps++;
      }
      printf("Case #%d: %d\n",cases,ans);
    }
    cases++;
  }
}