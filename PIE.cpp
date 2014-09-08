#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}


long double pi=3.14159265358979323846264338327950;
int n, f;

bool check (long double num, long double arr[]) {
  if (num == 0) return false;
  int frnds = 0;
  for (int i = 0; i < n; i++) {
    frnds += (int)(arr[i]/num);
  }
  if (frnds >= f) return true;
  else return false;
}


long double binarySearch(long double arr[]) {
  long double first = 0; long double last = arr[n-1];

  while (last - first >= 1e-6) {
    long double mid = (first + last)/2;
    if (check(mid,arr)) {
      first = mid;
    }
    else last = mid;
  }
  return first;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    inp(n); inp(f);
    f++;
    long double arr[n];
    for (int i = 0; i < n; i++) {
      scanf("%Lf",&arr[i]);
      arr[i] = pi*arr[i]*arr[i];
    }
    sort (arr, arr+n);
    long double ans = binarySearch(arr);
    printf("%.4Lf\n",ans);
  }
}