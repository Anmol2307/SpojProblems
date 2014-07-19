/*
written by- Piyush Golani
language- c++
country- India
College- N.I.T Jamshedpur
*/
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<cctype>
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
 
//////////////////////////////////////////////////////
 
 
int L[1001][1001],seg[1001][1001];
char A[1001],B[1001];
int n,m,k;
 
int lcs()
{
    f(i,1,n+1)
    {
        f(j,1,m+1)
        {
            L[i][j]= max(L[i-1][j],L[i][j-1]);
            seg[i][j]=0;
            if(A[i-1]==B[j-1])
            {
                seg[i][j]=seg[i-1][j-1]+1;
                if(seg[i][j]>=k)
                {
                    f(g,k,seg[i][j]+1)
                    {
                        L[i][j]=max(L[i][j],L[i-g][j-g]+g);
                    }
                }
            }
        }
    }
    return L[n][m];
}
 
 
int main()
{
    while(1)
    {
        si(k);
        if(k==0) break;
        scanf("%s",A);
        scanf("%s",B);
        n=strlen(A);
        m=strlen(B);
        printf("%d\n",lcs());
    }
}
 