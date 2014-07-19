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

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

void print(vector< vector<double> > A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << A[i][j] << "\t";
            if (j == n-1) {
                cout << "| ";
            } 
        }
        cout << "\n";
    }
    cout << endl;
}

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

double det(int n,double mat[10][10]) {
  double submat[10][10];
  double d=0;  
    if(n==2) return( (mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]));
    else{  
        for(int c=0;c<n;c++){  
            int subi=0;   //submatrix's i value
            for(int i=1;i<n;i++)
            {  
                int subj=0;
                for(int j=0;j<n;j++){
                        if(j==c)
                            continue;
                        submat[subi][subj]=mat[i][j];
                        subj++;
                    }
                  subi++;
        
                }
          d=d+(pow(-1,c)*mat[0][c]*det(n-1 ,submat));
        }
    }
    return d;
}


int main () {
    int t;
    inp(t);

    while (t--) {
        int n,x,d;
        inp(n);inp(x);inp(d);
        vector<LL> g;

        for (int i =0; i <=n; i++) {
            int y;
            inp(y);
            g.push_back(y);
        }
        vector<double> line(n+1,0);
        vector< vector<double> > A(n+1,line);
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                A[i][j] = pow(x + i*d,n-j);
            }
        }
        // for (int i=0; i<=n; i++) {
        //     A[i][n] = g[i];
        // }

        // print(A);

        vector<double> ans(n+1);
        // ans = gauss(A);
        for (int i = 0; i <=n; i++) {
            for (int j = 0; j<=n; j++) {
                A[j][i] = g[j];
            }
            ans[i] = det(n,A);
        }

        // Print result
        // cout << "Result:\t";
        for (int i=n; i>=0; i--) {
            printf("%lg ",ans[i]);
        }
        cout << endl;

    }

}