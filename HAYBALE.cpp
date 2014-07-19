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

//////////////////////////////////////////////////////////////////////////////////  

int n;
int tree[1000001];
int arr[1000001];

void update(int idx ,int val){
  while (idx <= n){
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

void updateRange(int a, int b, int v){
  update(a, v);   
  update(b + 1, -v);
}

int query(int b){     
    int sum = 0;
    // int b;     
    for(; b > 0; b -= b&(-b))   sum += tree[b];
    return sum;
}    

int readSingle(int idx){
  int sum = tree[idx]; // sum will be decreased
  if (idx > 0){ // special case
    int z = idx - (idx & -idx); // make z first
    idx--; // idx is no important any more, so instead y, you can use idx
    while (idx != z){ // at some iteration idx (y) will become z
      sum -= tree[idx]; 
  // substruct tree frequency which is between y and "the same path"
      idx -= (idx & -idx);
    }
  }
  return sum;
}


int main () {

  int k;
  inp(n);inp(k);
 

  for (int i = 0; i < k; i++) {
    int x, y;
    inp(x);inp(y);
    // arr[x]+=1;
    // arr[y+1] -=1;
    updateRange(x,y,1);
  }
  for (int i=1; i<= n; i++) {
      arr[i]=query(i);
      // arr[i]=arr[i]+arr[i-1];
  }
  // for (int i=1; i<= n; i++) {
  //     cout << arr[i]<< " ";
  // }
  // cout << endl;
  sort(arr+1,arr+n+1);
  printf("%d\n",arr[(n+1)/2]);
}