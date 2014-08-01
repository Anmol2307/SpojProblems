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

int main () {
  int n;
  inp(n);
  char arr[7];
  map <int, int> total;
  vector <int> vec;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%s",arr);
    scanf("%d",&x);
    // printf("%s\n",arr);
    if (strcmp(arr, "insert") == 0) {
      // printf("%d %lu\n",x,total.count(x));
      if (total.count(x) == 0) {
        total[x] = 1;
        // printf("%s\n", );("HERE\n");
      }
      else {
        total[x]++;
        if (total[x] == 2) {
          vec.push_back(x);
        }
      }
    }
    else {
      if (total.count(x) > 0) {
        total[x]--;
        if (total[x] == 1) {
          vec.erase(remove(vec.begin(), vec.end(), x), vec.end());
        }
        if (total[x] == 0) {
          total.erase(x);
          // printf("HERE%d\n",total[2]); 
        }
      }
    }
    // if (i==7) {
    //   printf("%d %lu\n",total[2],total.size());
    // }
    if (vec.size() != 0 && total.size() >= 2) {
      printf("both\n");
    }
    else if (vec.size() == 0 && total.size() >= 2) {
      printf("hetero\n");
    }
    else if (vec.size() != 0 && total.size() < 2) {
      printf("homo\n");
    }
    else {
      printf("neither\n");
    }

  }
}