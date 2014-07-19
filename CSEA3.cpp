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

///////////////////////////////////////////////////////////////////

int main () {
	
	int t;
	while (cin >> t && t != 0) {
		string str;
		cin >> str;
		int sz = str.size();
		int x = sz/t;
		char arr[x][t];
		int k = 0;
		int j = -1;
		for (int i = 0; i < x; i++) {
			if (j == -1) {
				j+= 1;
				while (j < t) {
					arr[i][j] = str[k];
					k++;
					j++;
				}
			}
			else if (j==t) {
				j -= 1;
				while (j >= 0) {
					arr[i][j] = str[k];
					k++;
					j--;
				}
			}	
		}
		// for (int l = 0; l < x; l++) {
		// 	for (int m = 0; m < t; m++) {
		// 		cout << arr[l][m] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		for (int i = 0 ; i < t; i++) {
			for (int l = 0; l < x; l++) {
				cout << arr[l][i];
			}
		}
		cout << endl;
	}
}