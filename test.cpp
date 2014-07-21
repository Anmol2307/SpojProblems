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
#include <climits>

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

vector < int > ind;

void swap(int x, int y){
    int temp = ind[x];
    ind[x]=ind[y];
    ind[y]=temp;

    return;
}

void permute(int k,int size){
    int i;

    if (k==0)
        return;
    else{
        for (i=k-1;i>=0;i--){
            swap(i,k-1);
            permute(k-1,size);
            swap(i,k-1);
        }
    }

    return;
}

int go (vector < int > &v) {
  int ans = 1;
    int n = v.size();
    vector < int > d(n, 1);
    for(int i = 1; i < n; ++i) {
        int mmax = -1;
        for(int j = 0; j < i; ++j) {
            if(v[j] < v[i] && (mmax == -1 || d[mmax] < d[j])) {
                mmax = j;
            }
        }
        if(mmax != -1) 
            d[i] += d[mmax];
        ans = max(ans, d[i]);
    }
    return ans;
}

void printArray(int size){
    int i;

    for (i=0;i<size;i++)
        std::cout << ind[i] << " ";

    std::cout << std::endl;

    return;
}

int main () {
    int test_case;
    scanf("%d", &test_case);
    while(test_case--) {
        int c, n;
        scanf("%d%d", &c, &n);
        int t = n * c;
        vector < int > colors(t), values(t);
        for(int i = 0; i < t; ++i) {
            scanf("%d%d", &colors[i], &values[i]);
        }
        
        for(int i = 0; i < c; ++i) {
            ind.push_back(i+1);
        }
        // for(int i = 0; i < c; ++i) {
        //     printf("%d ",ind[i]);
        // }
        // printf("\n");

        int mmin = INF;
        vector < int > v(t);
        int mat[c+1][n+1];
        // while (1) {
            // printf("HERE\n");
            permute(c,c);
            // printf("HERE\n");
            printArray(c);
            int cnt = 0;
            for(int i = 0; i < c; ++i) {
                for(int j = 0; j < n; ++j) {
                    mat[ind[i]][j] = cnt++;
                }
            }
            for(int i = 0; i < t; ++i) {
                v[i] = mat[colors[i] - 1][values[i] - 1];
            }
            mmin = min(mmin, t - go(v));
        // }

        // do {
        //     int cnt = 0;
        //     for(int i = 0; i < c; ++i) {
        //         for(int j = 0; j < n; ++j) {
        //             mat[ind[i]][j] = cnt++;
        //         }
        //     }
        //     for(int i = 0; i < t; ++i) {
        //         v[i] = mat[colors[i] - 1][values[i] - 1];
        //     }
        //     mmin = min(mmin, t - go(v));
        // }while(next_permutation(ind.begin(), ind.end()));
        


        printf("%d\n", mmin);
    }
    return 0;
}