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

  int t;
  inp(t);
  char arr[63];
  int val[37];
  memset(val,-1,sizeof(val));
  int c = 1;
  while (t--) {
    scanf("%s",arr);
    int len = strlen(arr);
    bool used = false;
    
    if (arr[0] >= 97 && val[arr[0]-'a'+10] == -1) {
      val[arr[0]-'a'+10] = 1;
    }
    else if (arr[0] >= 48 && val[arr[0]-'0'] == -1) {
      // printf("HERE\n");
      val[arr[0]-'0'] = 1;
    }

    if (arr[1] >= 97 && val[arr[1]-'a'+10] == -1) {
      val[arr[1]-'a'+10] = 0;
      used = true;
    }
    else if (arr[1] >= 48 && val[arr[1]-'0'] == -1) {
      val[arr[1]-'0'] = 0;
      used = true;
    }

    
    int j = 2;
    for (int i = 2; i < len; i++) {
      if (arr[i] >= 97 && val[arr[i]-'a'+10] == -1) {
        if (used) {
          val[arr[i]-'a'+10] = j;
          j++;
        }
        else {
          val[arr[i]-'a'+10] = 0;
          used = true;
        }
      }
      else if (arr[i] >= 48 && val[arr[i]-'0'] == -1) {
        if (used) {
          val[arr[i]-'0'] = j;
          j++;
        }
        else {
          val[arr[i]-'0'] = 0;
          used = true;
        }
      }
    }

    // for (int i = 0; i < len; i++) {
    //   if (arr[i] >= 97) {
    //     // ans += val[arr[i]-'a'+10]*pow(len,len-i-1);
    //     printf("%d ",val[arr[i]-'a'+10]);
    //   }
    //   else if (arr[i] >= 48) {
    //     // ans += val[arr[i]-'0']*pow(len,len-i-1);
    //     printf("%d ",val[arr[i]-'0']);
    //   }
    // }
    // printf("\n%d\n", j);
    // exit(0);


    long long int ans = 0;
    for (int i = 0; i < len; i++) {
      if (arr[i] >= 97) {
        // ans += (LL)(((LL)val[arr[i]-'a'+10])*((LL)pow(j,len-i-1)));
        ans = ans * j + val[arr[i]-'a'+10];
      }
      else if (arr[i] >= 48) {
        // ans += (LL)(((LL)val[arr[i]-'0'])*((LL)pow(j,len-i-1)));
        ans = ans * j + val[arr[i]-'0'];
      }
    }
    printf("Case #%d: %lli\n",c,ans);
    c++;
  }
}