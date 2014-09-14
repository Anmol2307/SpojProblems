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
typedef unsigned long long lli;


int main () {
  int t;
  inp(t);

  while (t--) {
    lli n;
    scanf("%llu\n",&n);
    if (n == 0 || n == 1) {
      printf("0\n");
      continue;
    }
    lli sum = n-1;
    lli k = 2;
    lli val = sqrt(n);
    lli z = 0;
    while (k <= val) {
      z= (n/k)-k;
      sum += (k*(z+1)+z*(2*(k+1)+(z-1))/2);
      k++;
    }
    printf("%llu\n",sum);
  }
}