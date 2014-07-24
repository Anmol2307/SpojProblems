#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
 
#define ll unsigned long long
#define MAX 32000
#define LMT 180
 
unsigned flag[MAX/64];
unsigned prime[3500], total;
 
#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
 
 
 
void sieve()
{
        unsigned i, j, k;
        for(i=3;i<LMT;i+=2)
                if(!chkC(i))
                        for(j=i*i,k=i<<1;j<MAX;j+=k)
                                setC(j);
        prime[1] = 2;
     
        for(i=3,j=2;i<MAX;i+=2)
        {
                if(!chkC(i))
                {
                    prime[j++] = i;
                }
        }                
        total = j;
        
}
 
int f(int a,int b,int div)
{
    unsigned int cnt=0,v=0;
    for(int i=a;i<=b;i++)
    {
        int h=i,ans=1;
        for(int j=1,t=prime[j];j<total && t <= sqrt(h); t = prime[++j])
        {
                v=0;
                if(h%t==0)
                {
                        
                        while(h%t==0)
                        {
                                v++;
                                h/=t;
                        }
                        
                }
                ans=ans*(v+1);
                if(h==1)
                    break;
        }
        if (h != 1) {
          ans *= 2;
        }
        if(ans==div){
            // printf("NUM %d\n",i);
            cnt++;
        }
     }
     return cnt;
}
 
 
int main()
{
     sieve();
     int a,b;
     int div;
     scanf("%d%d%d",&a,&b,&div);
     int cnt=f(a,b,div);
     printf("%d\n",cnt);
     return 0;
}