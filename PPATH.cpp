#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cctype>
using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define INF 2000000000
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000

typedef long long LL;

string inttostring(int n)
{
  stringstream a;
  a<<n;
  string A;
  a>>A;
  return A;
}

int stringtoint(string A)
{
  stringstream a;
  a<<A;
  int p;
  a>>p;
  return p;
}

///////////////////////////////////////////////////////////////////////////////////////////

vector <int> primes;
vector <int> isprime(10000,1);
bool prime[10000],visited[10000];
int d[10000];


void SieveEratosthenes () {

  isprime[0] = 0;
  isprime[1] = 0;
  for (int i = 2; i*i < 10000; i++) {
    if (isprime[i]){
      for (int j = i*i; j < 10000; j+=i) {
        isprime[j] = 0;
      }
    }
  }
  f(i,0,10000){
    if (isprime[i]) primes.pb(i);
  }
}


void genPrime(int a,int b){
  int p,l,i;
  memset(prime,true,sizeof(prime));
  for(p=2;p*p<=b;p++){
    l=a/p;
    l*=p;
    for(i=l;i<=b;i+=p){
      if(i>=a && i!=p)
        prime[i]=false;
    }
  }
}

int bfs(int a,int b){
  memset(visited,false,sizeof(visited));
  memset(d,-1,sizeof(d));
  queue<int>q;
  q.push(a);
  visited[a]=true;
  int c=0,i,temp,j,h,u;
  char num[8];
  d[a]=0;
  while(!q.empty()){
    u=q.front();
    q.pop();
    sprintf(num,"%d",u);
    for(i=0;i<4;i++){
      for(j=0;j<=9;j++){
        if(i==0 && j==0)
          continue;
        else{
          num[i]=j+'0';
          temp=atoi(num);
          //cout << "TMP " << temp;
          if(!visited[temp] && prime[temp] && temp!=u){
            q.push(temp);
            visited[temp]=true;
            d[temp]=d[u]+1;
            if(temp==b)
              return d[b];
          }
        }
      }
      sprintf(num,"%d",u);
    }
  }
  return d[b];
}

int main () {
  int t;
  cin >> t;
  genPrime(1000,9999);
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x==y) {
      cout << 0 << endl;
      continue;
    }
    int ans = bfs(x,y);
    cout  << ans << endl;
  }
}