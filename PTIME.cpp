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

#define MAX 10005
vector <int> primes;
int prime[MAX];

void pre () {
  for (int i = 2; i < 105; i++) {
    if (prime[i] == 0) {
      for (int j = 2*i; j < MAX; j+=i) {
        prime[j] = 1;
      }
    }
  }

  for (int i = 2; i < MAX; i++) {
    if (prime[i] == 0) primes.push_back(i);
  }
}

int main () {
  int n;
  inp(n);
  pre();
  // for (int i = 0; i < primes.size();i++) {
  //   printf("%d ",primes[i]);
  // }
  // printf("\n");
  // exit(0);
  int i = 0;
  vector <pair <int,int> > vec; 
  int sz = primes.size();
  while (i < sz && primes[i] <= n) {
    int val = primes[i];
    int sum = 0;
    int x = val;
    while (n/x) {
      sum += n/x;
      x *= val;
    }
    vec.push_back(pair<int,int>(primes[i],sum));
    i++;
  }
  printf("%d^%d ",vec[0].first,vec[0].second);
  for (int i = 1; i < vec.size(); i++) {
    printf("* %d^%d ",vec[i].first,vec[i].second);
  }
  printf("\n");
}
