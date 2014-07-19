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

int main () {
	
	
	int t;
	cin >> t;
	int val[27];
	int valid[27];
	while (t--) {
		
		string str;
		cin >> str;
		memset(val,0,sizeof(val));
		memset(valid,0,sizeof(valid));
		int i=1;
		int j=1;
		
		for (i = 1; i < 27; i++) {
			if (!valid[i]) {
				for (j=1;j<27;j++) {
					//cout << "Here " << j << endl;
					//if (j==2) exit(0);
					queue<int> q;			
					if (!valid[j]) {
						val[i] = j;
						valid[i] = 1;
						q.push(i);
						int k = i;
						int l = j;
						bool flag = false;
						while (1) {
							if (!valid[l]) {
								val[l] = (int)str[k-1] - 64;
								valid[l] = 1;
								q.push(l);
								k = l;
								l = val[l];
							}
							else if (val[l] == (int)str[k-1] - 64) {
								flag = true;
								break;
							}
							else {
								//cout << "Here " << j << endl;
								break;
							}
						}
						if (flag) {
							break;
						}
						else {
							//cout << "Here " << q.size() << endl;
							while (!q.empty()) {
								//cout << "HH " << q.front() << endl;
								valid[q.front()] = 0;
								q.pop();

							}
							//cout << "HERE " << endl;
							continue;
						}
					}
				}
				if (j==27) {
					cout << "No" << endl;
					break;
				}
			}
		}
		
		if (i == 27) cout << "Yes" << endl;
		
		
		
		// for (i = 1; i < 27; i++) {
		// 	if (!valid[i]) {
		// 		for (j = 1; j < 27; j++) {
		// 			if (!valid[j]) {
		// 				val[i] = j;
		// 				valid[i] = 1;
		// 				if (!valid[j]) {
		// 					val[j] = (int)str[i-1] - 64;
		// 					valid[j] = 1;
		// 				}
		// 				else if (valid[j] && val[j] == ( (int)str[i-1] - 64)) {
		// 					break;
		// 				}
		// 				else {
		// 					continue;
		// 				}
		// 			}
		// 		}
		// 		//cout << j << " HERE" << endl;
		// 		if (j==27) {
		// 			cout << "No" << endl;
		// 			break;
		// 		}
		// 	}
		// }
		// if (i == 27) cout << "Yes" << endl;
	}
}