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

#define MAX 1000005
typedef long long int lli;

lli sum[MAX];
lli fun[MAX];

void pre () {
  for (int i = 2; i < MAX; i++) {
    sum[i] = 1;
  }

  for (lli i = 2; i < 1005; i++) {
    for (lli j = 2*i; j < MAX; j+=i) {
      sum[j] += i;
      if (j/i >= 1005) {
        sum[j] += j/i;
        if (i == j/i) sum[j] -= i;
      }
    }
  }
  for (int i = 2; i < MAX; i++) {
    fun[i] = fun[i-1] + sum[i];
  }
}

int main () {
  pre();
  int t;
  inp(t);

  while (t--) { 
    int n;
    inp(n);

    printf("%llu\n",fun[n]);
  }
}
