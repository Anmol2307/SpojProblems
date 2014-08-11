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
#include <bitset>

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
#define i64 unsigned long long


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

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}



int main () {
  int t;
  inp(t);
  int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
  while (t--) {
    i64 a,b;
    scanf("%llu %llu",&a,&b);   
    bitset<64> ba(a);
    bitset<64> bb(b);

    int counta = ba.count();
    int countb;
    int i = 0;
    int ans = 0;
    while (ba.to_ulong() <= bb.to_ulong()) {
      bitset<64> test= ba;
      if (counta < prime[i]) {
        if (ba[0] == 1) {
          ba <<= 1;
          ba.set(0); 
        }
        else {
          ba.set(0);
        }
        counta++;
      }
      else if (counta == prime[i]){
        while (test.to_ulong() <= bb.to_ulong()) {
          printf("HERE %lu\n",test.to_ulong());
          ans++;
          test <<= 1;
        }
        if (ba[0] == 1) {
          ba <<= 1;
          ba.set(0); 
        }
        else {
          ba.set(0);
        }
        counta++;
      }
      else {
        i++;
      }
      // printf("%lu\n",ba.to_ulong());
    }
    printf("%d\n",ans);
  }
}