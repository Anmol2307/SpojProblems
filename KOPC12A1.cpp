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

pair<int,int> arr[10001];
int n;
    
bool pairCompare (const pair<int,int>& firstPair, const pair<int,int>& secondPair) {
  if (firstPair.first == secondPair.first) {
    return firstPair.second < secondPair.second;
  }
  return firstPair.first < secondPair.first;  
}

long long int func (int x) {
  long long int ans = 0;

  for (int i = 0; i < n; i++) {
    ans += abs(arr[x].first - arr[i].first)*arr[i].second;
  }
  return ans;
}

long long int ternarySearch () {
  int p = 0, s = n-1;
  long long int ans = 0;
  int q, r;
  while (s -p >= 3) {
    q = (2*p + s)/3;
    r = (p + 2*s)/3;
    if (func(q) > func(r)) {
      p = q;
    }
    else s = r;
  }
  ans = func(p);

  for (++p; p <= s;++p) {
    ans = min(ans,func(p));
  }

  return ans;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    inp(n);

    for (int i = 0; i < n; i++) {
      inp(arr[i].first);
    }
    for (int i = 0; i < n; i++) {
      inp(arr[i].second);
    }
    sort(arr, arr+n, pairCompare);
    long long int ans = ternarySearch();
    printf("%lli\n",ans);
  }
}