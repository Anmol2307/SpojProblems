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
typedef struct {
	int from , to;
} t_poster;

int posters;
vector<t_poster> poster;
//t_poster poster[44444];


void read_input () {
	cin >> posters;
	t_poster empty = {0,0};
	poster.assign(posters+1,empty);
	f(i,0,posters) {
		cin >> poster[i+1].from >> poster[i+1].to;
	}
}

int compare_ints (const void * ptr1, const void * ptr2) {
	return *((int*) ptr1) - *((int*) ptr2);	
}
int values;
vector<int> value;
//int value[88888];

void collect_values() {
	int i, j;
	for (i = 1; i <= posters;i++) {
		value.push_back(poster[i].from);
		value.push_back(poster[i].to);
	}
	values = value.size();
	
	//qsort(value,values,sizeof(int),compare_ints);
	sort(value.begin(),value.end());
	cout << endl;
	for (j=0,i=1;i<values;i++) {
		if (value[i] != value[j]) {
			value[++j] = value[i];
		}
	}
	values = j+1;
	// for (i = 0; i < values; i++) {
	// 	cout << value[i] << " ";
	// }
}

int find_value (int n) {
	
		int l,m,h;
		l=0; h = values;
		while (l < (h -1)) {
			m = (l + h)/2;
			if (value[m] <= n) l = m;
			else h = m;
		}
		return l;
}

int count_visibles () {
	vector<int> wall(values,0);
	//static int wall[88888];
	vector<int> visible(posters+1,0);
	//static int visible[44444];
	
	int p;
	//vector<int>::iterator f,t;
	int f;
	int t;
	int result=0;
	
	//f(w,0,values) wall[w] = 0;
	for (p=1;p<=posters;p++) {
		f = find_value (poster[p].from) ;
		t = find_value (poster[p].to) ;
		for (int w=f;w<=t;w++) wall[w] = p; 
	}
	//for (p=1;p<=posters;p++) visible[p] = 0;
	f(w,0,values) visible[wall[w]] = 1;
	for (p=1; p<=posters;p++) {
		if (visible[p]) result++;
	}
	return result;
}

int main () {
	int t;
	cin >>t;
	while (t--) {
		read_input();
		collect_values();
		cout << count_visibles() << endl;
	}
}


