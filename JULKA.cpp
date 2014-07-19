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

void funminus(string a, string b) {
  int carry = 0;

  int lena = a.size();
  int lenb = b.size();
  string final = "";
  
  for (int i = lenb-1; i >= 0; i--) {
    if (b[i] > a[lena-lenb+i]) {
      int ans = (a[lena-lenb+i] - '0') + carry+ 10 - (b[i]- '0');
      final.insert(0,inttostring(ans));
      carry = -1; 
    }
    else {
      int ans = (a[lena-lenb+i] - '0') - (b[i]- '0');
      final.insert(0,inttostring(ans));
      carry = 0;
    }
  }
  for (int i = lenb; i < lena; i++) {
    if ((a[lena-i-1] - '0') + carry < 0) {
      int ans = (a[lena-i-1] - '0') + carry+ 10;
      carry = -1;
      final.insert(0,inttostring(ans));
    }
    else {
      int ans = (a[lena-i-1] - '0') + carry;
      carry = 0;
      final.insert(0,inttostring(ans));
    }
  }
  int i = 0;

  while (final[i] == '0') {
    i++;
  }
  final = final.substr(i,final.size()-i);
  cout << final << endl;
  
  
}


int  main () {

  int t = 1;
  while (t--) {
    string x,y;
    cin >> x >> y;
    funminus(x,y);

  }


}