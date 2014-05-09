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
using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define INF 2000000000
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000

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
string reverse (string str) {
  int sz = str.size();
  string newstr = str;
  for (int i = 0; i < sz/2; i++) {
    char x = newstr[i];
    newstr[i] = newstr[sz-i-1];
    newstr[sz-i-1] = x;
  }
  return newstr;
}


// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  int ans = 0;;
  for (int i = 1; i < n-1; i++) {
    if (P[i] >= maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
    //cout << "HERE " << i + P[i] << " " << 2*s.size() + 1 << endl;
    if (i + P[i] == 2*s.size() + 1) {
      if (P[i] >= ans) ans = P[i];
    }

  }
  // for (int i = 1; i < n-1;i++) {
  //     cout << P[i] << " ";
  // }
  // cout << endl;
  //exit(0);
  //cout << "MAX " << ans << endl;
  delete[] P; 
  return s + reverse(s.substr(0, s.size() - ans));
  //return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

int main () {
  string str;
  while (cin>>str) {
    //cout << str << " ";
    string ans = longestPalindrome(str); 
    cout << ans << endl;
  }
}
