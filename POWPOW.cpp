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
#define MAX 100004 
#define MOD 1000000007
llu fact[MAX];

void binomialCoeff() {  
    fact[0] = 1;
    for (int k = 1; k < MAX; k++) {
      fact[k] = ((fact[k-1]*2)/k)*(2*k-1);
    }
}

llu modpow(llu base, llu exp, llu modulus) {
  base %= modulus;
  llu result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main () {
  binomialCoeff();
  int t;
  inp(t);
  while (t--) {
    llu a,b,n;
    scanf("%llu %llu %llu",&a,&b,&n);
    llu x = modpow(fact[n],b,MOD-1);
    llu ans = modpow(a,x,MOD);
    printf("%llu\n",ans);
  }
}