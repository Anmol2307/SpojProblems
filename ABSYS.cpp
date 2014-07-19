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
	
	int t;
	cin >> t;
	string str,fart;
	getline(cin,fart);
	getline(cin,str);
		
	while (t--) {
		string str,fart;
		getline(cin,str);
		//cout << fart << endl;
		getline(cin,fart);
		//cout << str << endl;
	
		size_t foundp = str.find('+');
		size_t founde = str.find('=');
		size_t foundm = str.find('m');
		//cout << foundm << " " << founde << endl;
		if (foundm > founde) {
			int num1 = stringtoint(str.substr(0,foundp-1));
			int num2 = stringtoint(str.substr(foundp+2,founde-foundp-2));
			//cout << foundp+2 << " " << founde-foundp-2 << endl;
			//cout << num1 << " " << num2 << endl;
			cout << str.substr(0,founde+2) << inttostring(num1+num2) << endl;
		}
		else {
			if (foundm < foundp) {
				int num1 = stringtoint(str.substr(founde+2));
				int num2 = stringtoint(str.substr(foundp+2,founde-foundp-2));
				//cout << num1 << " " << num2 << endl;
				cout << inttostring(num1-num2) << str.substr(foundp-1) << endl;
			}
			else {
				int num1 = stringtoint(str.substr(0,foundp-1));
				int num2 = stringtoint(str.substr(founde+2));
				//cout << num1 << " " << num2 << endl;
				cout << str.substr(0,foundp+2) << inttostring(num2-num1) << str.substr(founde-1) << endl;
			}
		}
		
	}
}