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
#include <climits>

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
#define EPS 1e-9
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)


typedef long long int LL;

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

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

///////////////////////////////////////////////////////////////////////////////////////////


#define ll unsigned long long
#define MAX 1000
#define LMT 35
#define NUM 1000000
 
unsigned flag[MAX/64];
unsigned prime[MAX], total;
long long int arr[NUM];
 
#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
 
 
 
void sieve()
{
        unsigned i, j, k;
        for(i=3;i<LMT;i+=2)
                if(!chkC(i))
                        for(j=i*i,k=i<<1;j<MAX;j+=k)
                                setC(j);
        prime[1] = 2;
     
        for(i=3,j=2;i<MAX;i+=2)
        {
                if(!chkC(i))
                {
                    prime[j++] = i;
                }
        }                
        total = j;
        
}

void func()
{
    unsigned int v=0;
    arr[0] = 0;
    arr[1] = 0;
    for(int i=2;i<NUM;i++)
    {
        // int i = a;
        int h=i;
        long long int ans=1;
        for(int j=1,t=prime[j];j<total && t <= sqrt(h); t = prime[++j])
        {
                v=0;
                if(h%t==0)
                {
                        
                        while(h%t==0)
                        {
                                v++;
                                h/=t;
                        }
                        
                }
                ans=(LL)(((LL)ans)*((LL)(v+1)));
                if(h==1)
                    break;
        }
        if (h != 1) {
          ans = (LL)(ans*2);
        }
        arr[i] = arr[i-1] + ans -1; 
     }
}






int main  () {
    sieve();
    func();
    int t;
    inp(t);

    while (t--) {
        int n;
        inp(n);
        printf("%lli\n",arr[n]);
        // printf("%i\n",func(n));
    }
    
}