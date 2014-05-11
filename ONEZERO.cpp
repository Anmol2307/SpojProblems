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
#include <list>
#include <stack>
#include <fstream>
#include <utility>
#include <iomanip>

using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000
#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PI acos(-1.0)
#define EPS 1e-9
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)


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


bool flag[20003];
int  q[20003];
int n;

struct pre
{
  int p, c;
};

pre pre[20003];

int mod(int a,int b)
{
  if(a<b)
  {
    return a;
  }
  else
    return a%b;
}

void bfs(int s)
{
  int p[2];
  int qh,qt,i,u;
  qh=qt=0;
  q[qt++]=s;
  pre[s].p=-1;
  pre[s].c='1';
  flag[s]=true;
  while(qh<qt)
  {
    int u=q[qh++];
    p[0]=mod(u*mod(10,n),n);
    p[1]=mod(p[0]+1,n);
    for(int i=0;i<2;i++)
    {
      if(!flag[p[i]])
      {
        flag[p[i]]=true;
        q[qt++]=p[i];
        pre[p[i]].c=i+'0';
        pre[p[i]].p=u;
      }
    }
  }


}

void printpath(int s)
{
  if(s==-1)
  {
    return;
  }
  printpath(pre[s].p) ;
  putchar(pre[s].c);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    if(n==1)  
    {
      cout<<1<<endl;
      continue;
    }
    for(int i=0;i<=n;i++)
    {
      flag[i]=false;
    }
    bfs(1);
    printpath(0);
    putchar('\n');
  }
  return 0;

}
