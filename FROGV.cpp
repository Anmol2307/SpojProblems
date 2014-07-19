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

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

// int binarySearch(int sortedArray[], int first, int last, int key) {
//    // function:
//    //   Searches sortedArray[first]..sortedArray[last] for key.  
//    // returns: index of the matching element if it finds key, 
//    //         otherwise  -(index where it could be inserted)-1.
//    // parameters:
//    //   sortedArray in  array of sorted (ascending) values.
//    //   first, last in  lower and upper subscript bounds
//    //   key         in  value to search for.
//    // returns:
//    //   index of key, or -insertion_position -1 if key is not 
//    //                 in the array. This value can easily be
//    //                 transformed into the position to insert it.
   
//    while (first <= last) {
//        int mid = (first + last) / 2;  // compute mid point.
//        if (key > sortedArray[mid]) 
//            first = mid + 1;  // repeat search in top half.
//        else if (key < sortedArray[mid]) 
//            last = mid - 1; // repeat search in bottom half.
//        else
//            return mid;     // found it. return position /////
//    }
//    return -(first + 1);    // failed to find key
// }
int binarySearch(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] >= key )
            r = m;
        else
            l = m;
    }
 
    return r;
}

int main () {

  int n,k,p;

  inp(n);inp(k);inp(p);
  int a[n];
  int b[n];
  int c[n];
  for (int i=0; i<n;i++) {
    inp(a[i]);
    b[i]=a[i];
  }
  sort(b,b+n);
  c[0]=0;
  for (int i =1; i<n; i++) {
    c[i] =  b[i]-b[i-1];
  }
  // for (int i =1; i<n; i++) {
  //   cout << b[i] << " ";
  // }
  // cout << endl;


  while (p--) {
    int x, y;
    inp(x); inp(y);
    if (abs(a[x-1] - a[y-1]) <= k) {
      printf("%s\n","Yes");
      continue;
    }
    int lb = binarySearch(b,-1,n-1,a[x-1]);
    int up = binarySearch(b,-1,n-1,a[y-1]);
    // cout << a[y-1] << " " << up << endl;
    int i;
    if (lb <= up) {
      for (i = lb+1; i <= up && c[i]<=k; i++) {
      }
      if (i==up+1) printf("%s\n","Yes");
      else printf("%s\n","No");
    }
    else {
      for (i = up+1; i <= lb && c[i]<=k; i++) {
      }
      if (i==lb+1) printf("%s\n","Yes");
      else printf("%s\n","No");
    }
  }

}