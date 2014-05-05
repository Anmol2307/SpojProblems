#include<iostream>
#include<string>
using namespace std;

int res=0,mark[52][52];
int m,n;

int p[]={-1,-1,-1,0,0,1,1,1};
int q[]={-1,0,1,-1,1,-1,0,1};

void dfs(char c[52][52],int x,int y,int cnt)
{
    res=max(res,cnt);

    for(int i=0;i<8;i++)
    {
        if(x+p[i]>=0 && x+p[i]<m && y+q[i]>=0 && y+q[i]<n && mark[x+p[i]][y+q[i]]==0)
        {
            if(c[x+p[i]][y+q[i]]==c[x][y]+1)
            {
                mark[x+p[i]][y+q[i]]=1;
                dfs(c,x+p[i],y+q[i],cnt+1);
            }
        }
    }
}

int main()
{
    char c[52][52];
    int t=0;

    while(cin>>m && m>0 && cin>>n && n>0)
    {
        res=0;

        for(int i=0;i<m;i++)
        {
            string s;  //Use file redirection
            cin>>s;

            for(int j=0;j<s.length();j++)
            {
                c[i][j]=s[j];
                mark[i][j]=0;
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(c[i][j]=='A')
                {
                    mark[i][j]=1;
                    dfs(c,i,j,1);
                }
            }
        }

        cout<<"Case "<<++t<<": "<<res<<endl;
    }
    return 0;
}
