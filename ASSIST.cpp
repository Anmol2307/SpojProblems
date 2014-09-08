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

vector <int> primes;
int prime[3001];

void pre () {
  for (int i = 2; i < 57; i++) {
    if (prime[i] == 0) {
      for (int j = 2*i; j < 3001; j+= i) {
        prime[j] = 1;
      }
    }
  }

  for (int i = 2; i < 3001; i++) {
    if (prime[i] == 0) primes.push_back(i);
  }
}
int main () {
  int n;
  pre();
  while (scanf("%d",&n) == 1) {
    if (n == 0) break;
    printf("%d\n",primes[n-1]);
  }
}