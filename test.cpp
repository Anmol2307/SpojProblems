#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

bool prime[10000],visited[10000];
int d[10000];

void genPrime(int a,int b){
	int p,l,i;
	memset(prime,true,sizeof(prime));
	for(p=2;p*p<=b;p++){
		l=a/p;
		l*=p;
		for(i=l;i<=b;i+=p){
			if(i>=a && i!=p)
				prime[i]=false;
		}
	}
}
int bfs(int a,int b){
	memset(visited,false,sizeof(visited));
	memset(d,-1,sizeof(d));
	queue<int>q;
	q.push(a);
	visited[a]=true;
	int c=0,i,temp,j,h,u;
	char num[8];
	d[a]=0;
	while(!q.empty()){
		u=q.front();
		q.pop();
		sprintf(num,”%d”,u);
		for(i=0;i<4;i++){
			for(j=0;j<=9;j++){
				if(i==0 && j==0)
					continue;
				else{
					num[i]=j+’0′;
					temp=atoi(num);
					//cout << "TMP " << temp;
					if(!visited[temp] && prime[temp] && temp!=u){
						q.push(temp);
						visited[temp]=true;
						d[temp]=d[u]+1;
						if(temp==b)
							return d[b];
					}
				}
			}
			sprintf(num,”%d”,u);
		}
	}
	return d[b];

}
int main(){
	int t,a,b,dist;
	scanf(“%d”,&t);
	genPrime(1000,9999);
	while(t–){
		scanf(“%d%d”,&a,&b);
		if(a==b){
			printf(“0\n”);
			continue;
		}
		dist=bfs(a,b);
		if(dist==-1)
			printf(“impossible\n”);
		else
			printf(“%d\n”,dist);
	}
	return 0;
}

