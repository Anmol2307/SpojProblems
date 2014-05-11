#include <iostream>
#include <cstdio>
using namespace std;
bool flag[20003];
int  q[20003];
int n;

struct pre
{
	int p, c;
};

pre pre[20003];

int mod(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
		return a%b;
}

void bfs(int s)
{
	int p[2];
	int qh,qt,i,u;
	qh=qt=0;
	q[qt++]=s;
	pre[s].p=-1;
	pre[s].c='1';
	flag[s]=true;
	while(qh<qt)
	{
		int u=q[qh++];
		p[0]=mod(u*mod(10,n),n);
		p[1]=mod(p[0]+1,n);
		for(int i=0;i<2;i++)
		{
			if(!flag[p[i]])
			{
				flag[p[i]]=true;
				q[qt++]=p[i];
				pre[p[i]].c=i+'0';
				pre[p[i]].p=u;
			}
		}
	}


}

void printpath(int s)
{
	if(s==-1)
	{
		return;
	}
	printpath(pre[s].p) ;
	putchar(pre[s].c);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		for(int i=0;i<=n;i++)
		{
			flag[i]=false;
		}
		bfs(1);
		printpath(0);
		putchar('\n');
	}
	return 0;

}
