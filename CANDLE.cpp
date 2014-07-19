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

bool pairCompare(const std::pair<int, int>& firstElem, const std::pair<int, int>& secondElem) {
 if (firstElem.second < secondElem.second){
 	return 1;
 }
 else if (secondElem.second == firstElem.second && secondElem.first > firstElem.first) {
 	return 1;
 }
 else return 0;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		pair<int,int> arr[10];
		
		for (int i = 0; i < 10; i++) {
			pair<int,int> p;
			p.first = i;
			cin >> p.second;
			arr[i] = p;
		}
		sort(arr,arr+10,pairCompare);
		// for (int i = 0; i < 10; i++) {
		// 	cout << arr[i].first << " " << arr[i].second << endl;
		// }
		// cout << endl;
		int k = 0;
		while (k < 10) {
			
			if (arr[k].first != 0 && k == 0) {
				string str;
				char ch = (char)(arr[k].first + 48);
				str.assign(arr[k].second+1,ch);
				cout << str << endl;
				break;
			}
			else if (arr[k].first != 0 && arr[k].second != 0) {
				string str;
				char ch = (char)(arr[k].first + 48);
				str.assign(1,ch);
				string str2;
				if (arr[k].second > arr[0].second){
					str2.assign(arr[0].second + 1,(char)(arr[0].first + 48));
				}
				else if (arr[k].second == arr[0].second){
					str2.assign(arr[k].second,(char)(arr[k].first + 48));
				}
				str.append(str2);
				cout << str << endl;
				break;
			}
			else if (arr[k].first != 0 && arr[k].second == 0) {
				string str;
				char ch = (char)(arr[k].first + 48);
				str.assign(arr[k].second+1,ch);
				cout << str << endl;
				break;
			}
			k++;
		}
		

	}
}