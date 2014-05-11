#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007


bool visited[110][110];
int n,m,grid[110][110],w[110][110],res;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void border_dfs(int x, int y, int h)
{
    visited[x][y]=true;
    w[x][y]=grid[x][y];
    for(int i=0;i<4;i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X>=0 && X<n && Y>=0 && Y<m)
            if(h<=grid[X][Y])
                if(!visited[X][Y])
                    border_dfs(X,Y, grid[X][Y]);
    }
}

int main()
{
    int t,kk=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        CLR(w);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
                w[i][j]=MX;

            }

            CLR(visited);

            for(int i=0;i<n;i++)
            {
                if(!visited[i][0])
                    border_dfs(i,0,grid[i][0]);
                if(!visited[i][m-1])
                    border_dfs(i,m-1,grid[i][m-1]);
            }
            for(int i=0;i<m;i++)
            {
                if(!visited[0][i])
                    border_dfs(0,i,grid[0][i]);
                if(!visited[n-1][i])
                    border_dfs(n-1,i,grid[n-1][i]);
            }

            res=0;
            while(1)
            {
                bool chk=true;

                for(int i=1;i<n-1;i++) {
                    for(int j=1;j<m-1;j++)
                    {
                        int mn=MX;
                        if(!visited[i][j])
                        {
                            for(int k=0;k<4;k++)
                            {

                                int X=i+dx[k];
                                int Y=j+dy[k];
                                mn=min(mn, max(grid[X][Y],w[X][Y]));
                            }
                            if(mn<w[i][j])
                            {
                                w[i][j]=mn;
                                chk=false;
                            }
                        }

                    }
                }
                if(chk)
                    break;
            }
            for(int i=1;i<n-1;i++)
                for(int j=1;j<m-1;j++)
                    if(w[i][j]>grid[i][j])
                        res+=w[i][j]-grid[i][j];
            cout<<res<<endl;

    }
    return 0;
}