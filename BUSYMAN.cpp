#include <cstdio>
#include <algorithm>
using namespace std;

pair< int, int >* pii;

inline bool comp(const pair< int, int > &a, const pair< int, int > &b) {
  return (a.second == b.second) ? a.first < b.first : a.second < b.second;
}

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

int main() {
  int t;
  inp(t);
  
  while(t--) {
    int n;
    inp(n); 
    pii = new pair<int,int>[n];
    
    for(int i = 0; i < n; i++) {
      inp(pii[i].first);
      inp(pii[i].second);
    }
    sort(pii, pii + n, comp);
    int cnt = 0, end = -1;
    
    for(int i = 0; i < n; i++) {
      if(pii[i].first >= end) {
        cnt++;
        end = pii[i].second;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}