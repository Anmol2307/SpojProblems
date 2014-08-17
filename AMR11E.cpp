#include <iostream>
#include <cmath>
#include <cstdio>

#define N 2670

using namespace std;

int prime[N+1];

void sieve(){
  prime[0]=1;
  prime[1]=1;
  for(long long i=2;i<=N;i++){
    if(!prime[i]){
      prime[i]=i;
      for(long long j=i;j*i<=N;j++){
        prime[j*i]=i;
      }
    }
  }
}

bool primeFactorize(int n){
    int ct=0,flag=0;
    while (n > 1){
      int p = prime[n] , e = 0 ;
      while (n % p == 0){
        n /= p; e++;
      }
      ct++;
      if(ct==3){
        flag=1;
        break;
      }
    }
    return flag;
}

int main(){

  sieve();
  int t;
  scanf("%d",&t);
  int tp[1001],ct=0;

  for(int i=30;i<2670 && ct <= 1000;i++){
    if(primeFactorize(i))tp[ct++]=i;
  }

  while(t--){
    int n;
    scanf("%d",&n);
    printf("%d\n",tp[n-1]);             
  }
  return 0;
}