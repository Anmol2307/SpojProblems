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

  int n;
  while (cin >> n && n != 0 ) {

    int arr[n+1];
    int order[n+1];
    f(i,1,n+1) {
      cin>>arr[i];
    }
    stack<int> stk;
    bool flag = true;
    int i = 1;
    int j = 1;
    while (i != n+1) {
      if (arr[j] == i) {
        order[i] = i;
        i++;
        j++;
      }
      // else if (!stk.empty() && stk.top() == i){
      //   stk.pop();
      //   order[i] = i;
      //   i++;
      // }
      else {
        stk.push(arr[j]);
        j++;
      }
      //cout << i << " " << j << endl;
      
      while (!stk.empty() && stk.top() == i) {
        stk.pop();
        order[i] = i;
        i++; 
      }

      if (j == n+1 && i != n+1) {
        flag = false;
        break;
      }
    }

    if (flag) cout << "yes" << endl;
    else cout << "no" << endl;
  }


}