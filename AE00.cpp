#include <cstdio>

int main()
{
    long long int n,i,j,count=0;
    scanf("%lld",&n);
    
    for(i=1;i<=n;i++)
    {
        for (j=i;j<=n;j++)
        {
            if(i*j>n)
                break;
            count++;    
        }
    }
    printf("%lld\n",count);
    return 0;
}