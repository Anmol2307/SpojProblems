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
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 222222


int main () {
  int t;
  inp(t);

  while (t--) {
    int p; inp(p);
    int l; inp(l);
    int arr[l];

    vector <priority_queue<int, vector<int>, greater<int> > >pq(l);

    rep(i,l) {
      inp(arr[i]);
    }

    sort(arr,arr+l);

    rep(i,l) {
      pq[i].push(arr[i]);
    }

    int total = 0;
    int ans = 0;
    int last[l];
    rep(i,l) last[i] = 1;
    while (total < p) {
      int mi = -1;
      int mv = INT_MAX;
      for (int i = 0; i < l; i++){
        if (pq[i].top() < mv) {
          mi = i;
          mv = pq[i].top();
        }
      }
      ans = mv;
      pq[mi].pop();
      pq[mi].push(mv + (last[mi]+1)*arr[mi]);
      last[mi]++;
      total++;
    }
    printf("%d\n",ans);
  }
}