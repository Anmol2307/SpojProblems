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
#define N 105
#define MX 10000000

int dis[N][N];
    

int main() {
  
  int n;
  inp(n);

  while( n != 0)
  {
    
    fu(i,0,n) fu(j,0,n) dis[i][j] = MX;

    fu(i,1,n)
    {
      int x; inp(x);
      string str;
      cin>>str;
      if(str == "true")
        dis[i][x] = 2;
      else
        dis[i][x] = 1;
    }

    fu(k,1,n)
    {
      fu(i,1,n)
      { 
        fu(j,1,n)
        {
          if(dis[i][j]>dis[i][k]+dis[k][j])
          {
            dis[i][j]=dis[i][k]+dis[k][j];
          }
        }
      }
    }

    int temp=0;
    fu(i,1,n)
    {
      if( dis[i][i] < INT_MAX/ 2 && dis[i][i] % 2 == 1)
      {
        cout<<"PARADOX"<<endl;
        temp = 1;
        break;
      }

    }
    if(temp == 0)
    {
      cout<<"NOT PARADOX"<<endl;
    }
    inp(n);
  }
  return 0;
}