#include <iostream>
#include <stdio.h>
using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

bool flag[1000001];
int prime[9000000], total;
 
 
void sieve()
{
    int i, j;
    for(i = 2; i < 3164; ++i)
    {
      if(flag[i]==1)
      {
        for(j = 2;i*j < 1000001;++j)
          flag[i*j] = 0;
      }
    }

    for (i = 2, j = 1; i < 10000001; i++) {
      if (flag[i]==1) {
        // printf("%d\n",i);
        prime[j++] = i;
      }
    }
    total = j;
}


int main () {
  for(int i = 1 ; i < 1000001; ++i)
        flag[i] = 1;
  sieve();
  int t;
  inp(t);
  while (t--) {
    int n;
    inp(n);
    int count = 0;
    for (int i = 1; prime[i]*prime[i] <= n && i < total; i++) {
      if (n%prime[i] == 0) {
        int power = 0;
        int num = prime[i];
        while (n%num == 0) {
          power++;
          n /= num;
        }
        if (power != 0 && power%2 == 0) {
          count++;
        }
        else count--;
      }
    }
    if (n != 1) count--;
    if (count  > 0) printf("%s\n","Psycho Number");
    else printf("%s\n","Ordinary Number");
  }
  return 0;
}