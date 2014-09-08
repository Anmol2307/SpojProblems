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

// BIT query and update functions
typedef long long int lli;
#define MOD 5000000

const int maxn = 100010;

int tree[maxn];

int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum = (sum + tree[idx])%MOD;
        idx -= (idx & -idx);
    }
    return sum;
}
  
void update(int idx, int val){
    while(idx <= maxn){
        tree[idx] = (tree[idx] + val)%MOD;
        idx += (idx & -idx);
    }
}


int main () {
  int n, k;
  inp(n); inp(k);
  k--;
  int arr[n];
  for (int i = 0; i < n; i++) {
    inp(arr[i]);
    arr[i]++;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int val = read(arr[i] -1);
    if (val >= k){
      ans = (ans + val - k + 1)%MOD;
    }
    update(arr[i],1);
  }
  printf("%d\n",ans);
}