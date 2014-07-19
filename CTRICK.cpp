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

struct node {
	int index;
	node* next;
};



int main () {
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin>>n;
		int arr[n+1];
		node* first = new node();
		first->index = 1; 
		node* n1 = new node();
		f(i,1,n) {
			node * n2 = new node();
			n2->index = i+1;
			if (i==1) first->next = n2;
			else n1->next = n2;
			n1= n2;
		}
		if (n==1) first->next = first;
		n1->next = first;
		f(i,0,n) {
			int j = i;
			while (j--) first = first->next; 
			arr[first->next->index] = i+1;
			//cout << arr[first->next->index] << endl;
			first->next = first->next->next;
			first = first->next;
			
		}
		f(i,1,n+1) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}














