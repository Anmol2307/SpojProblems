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

int lps[1000000];
string pat;
int m;


int computeLPSArray()
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < m)
    {
    	if(pat[i] == pat[len])
    	{
    		len++;
    		lps[i] = len;
    		i++;
    	}
       else // (pat[i] != pat[len])
       {
       	if( len != 0 )
       	{
           // This is tricky. Consider the example AAACAAAA and i = 7.
       		len = lps[len-1];

           // Also, note that we do not increment i here
       	}
         else // if (len == 0)
         {
         	lps[i] = 0;
         	i++;
         }
     }
 }
 return 0;
}

int main () {
	int t;
	cin >> t;

	for (int i =1; i <=t; i++) {
		int n;
		cin>>m;
		cin>>pat;
		computeLPSArray();
		printf("Test case #%d\n",i);
		for(int j=1;j<m;j++)
		{
			int miss_matched=j+1-lps[j];
			if((j+1)%miss_matched==0)
				if((j+1)/miss_matched>1)
					cout<<j+1<<" "<<(j+1)/miss_matched<<endl;
		}
		cout << endl;
	}

}