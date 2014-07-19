
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

vector <int> prime;
bool check[mm];
LL arr[mm];

void sieve () {

  for (int i=2; i < sqrt(mm); i++) {
    if (check[i]) {
      for (int j = i*i; j < mm; j+=i) {
        check[j] = 0;
      }
    } 
  }

  for (int i = 2; i < mm; i++) {
    if (check[i]) prime.push_back(i);
  }

}

void print () {

  for (int i = 0; i < prime.size(); i++) {
    cout << prime[i] << " ";
  }
  cout << endl;
}

int main () {


  int t;
  cin >> t;
  memset(check,1,sizeof(check));
  sieve();
  // print();
  // exit(0);
  arr[0]=0; arr[1]=0;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
      int j;
      for (j = 0; prime[j]<= i && i%prime[j] != 0; j++) {
        //cout << "HERE " << prime[j] << endl;
      }
      arr[i] = arr[i-1] + prime[j];
    }
    cout << arr[n] << endl;
  }
}