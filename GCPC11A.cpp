#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;
// #define mm 1000000000000

typedef long long LL;
// static bool check[mm];

int main () {
  int t;
  cin >> t;
  
  while (t--) {
    LL n,k;
    map <LL,LL> m;
    cin >> n >> k;
    LL d = 2;
    while (k > 1) {
        LL x = 0;
        while (k % d == 0) {
          k =(LL)(k/d);
          x++;
        }
        if (x!=0) m[d] = x;
        d = (LL)(d + 1);
        if ((LL)d*d > k){
          if (k > 1) {
            m[k] = 1;
          }
          break;
        }
    }
    
    // LL min = 9223372036854775807ULL;
    LL min = numeric_limits<LL>::max();
    for (map<LL,LL>::iterator it = m.begin(); it != m.end(); it++) {
      LL val = it->first;

      LL x = 0;
      while ((LL)(n/val)) {
        x = (LL)(x+n/val);
        if (numeric_limits<LL>::max() / it->first < val) break;
        val = (LL)(val*it->first);
      }
      
      if ((LL)(x/it->second) < min) min = (LL)(x/it->second);
    }
    cout << min << endl;

  }
  return 0;
}