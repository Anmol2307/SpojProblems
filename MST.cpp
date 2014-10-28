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
#define N 10005

typedef pair<int,pii> pip;

vector<pip> edges;
int parent[N];
int rank[N];

int find (int i) {
  if (parent[i] == i) return i;
  return find(parent[i]);
}

void Union (int a, int b) {
  int fp = parent[a];
  int sp = parent[b]; 
  
  if (rank[fp] < rank[sp]) {
    parent[fp] = sp;
  }
  else if (rank[fp] > rank[sp]) {
    parent[sp] = fp;
  }
  else {
    parent[sp] = fp;
    rank[sp]++; 
  }
}

int main () {
  int n, m;
  inp(n); inp(m);

  for (int i = 0; i < m; i++) {
    int x, y, w;
    inp(x); inp(y); inp(w);
    edges.push_back(pip(w,pii(x,y)));
  }

  sort(edges.begin(),edges.end());

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  ll ans = 0;
  int tot = 0;
  for (int i = 0; i < m && tot < n; i++) {
    int f = find(edges[i].ss.ff);
    int s = find(edges[i].ss.ss);
    if (f != s) {
      Union(f,s);
      ans += (ll)edges[i].ff;
      tot++;
    }
  }
  printf("%lli\n",ans);
}