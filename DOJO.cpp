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
 

 int main () {
  int t;
  scanf("%d",&t);

  while (t--) {
    int n,i;
    char m[2005];
    char j[2005];
    
    scanf("%d %s %d %s",&n,&m[0],&i,&j[0]);
    // cin >> n >>m >>i >> j;
    // cout << n%2 << " " << (m[strlen(m)-1]-'0')<< " " << (i+(j[strlen(j)-1]-'0'))<< endl;
    if (n%2 == 1 && (m[strlen(m)-1]-'0')%2 ==1 && (i+(j[strlen(j)-1]-'0'))%2==0) {
      printf("%s\n","Possible.");
    }
    else {
      printf("%s\n","Impossible.");
    }
  }
 }