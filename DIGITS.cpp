// Program to print all prime factors
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

LL stringtoint(string A)
{
  stringstream a;
  a<<A;
  LL p;
  a>>p;
  return p;
}

///////////////////////////////////////////////////////////////////////////////////////////
 
// A function to print all prime factors of a given number n
bool primeFactors(LL n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        //printf("%d ", 2);
        n = n/2;
        //ans.append(inttostring(2));
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= 9; i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            //printf("%d ", i);
            n = n/i;
            //ans.append(inttostring(i));
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2) {
        return 0;
        //cout << "HERE " << n << endl;
    }
    else return 1;
        //printf ("%d ", n);
}

string findans(LL value) {

    string ans = "";

    for (int i = 9; i >=2; i--) {
        while (value % i == 0) {
            value /= i;
            ans.insert(0,inttostring(i));
        }
        //cout << value << endl;
    }
    return ans;
}

int main () {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (n==0) {
            cout << 10 << endl;
            continue;
        }
        bool flag = primeFactors(n);
        //exit(0);
        int i = 1;
        LL val = n;;
        while (!flag) {
            val = n + mod*i;
            flag = primeFactors(val);
            i++;
        }
        cout << val << endl;
        cout << findans(val) << endl;
    }

}
 