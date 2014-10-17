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
#define N 1005


char mat[N][N];
int visited[N][N];
int cnt;
int prev_count;
int n, m;

void floodfill(int i,int j){
  if(i>=0&&j>=0&&i<n&&j<m)
    if(visited[i][j]==0){
      visited[i][j]=cnt;
    
      switch(mat[i][j]){
        case 'E':floodfill(i,j+1);
                break;
        case 'W':floodfill(i,j-1);
                break;
        case 'N':floodfill(i-1,j);
                break;
        case 'S':floodfill(i+1,j);
                break;
      }
      visited[i][j]=cnt;
    }
    else{
      cnt=visited[i][j];
      return;
    }
}

int main () {
  inp(n); inp(m);

  for (int i = 0; i < n; i++) {
    scanf("%s",mat[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        cnt = prev_count + 1;
        floodfill(i,j);
        if (prev_count < cnt) prev_count++;
      }
    }
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     printf("%d ",visited[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%d\n",prev_count);
}