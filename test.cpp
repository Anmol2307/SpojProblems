#include<iostream>
#include<stdio.h>
using namespace std;
bool primeSieve[1000001];
int primeNumbers[9000000];
int primeCount = 0;
void createSieve()
{
    for(int i = 2; i < 3164; ++i)
    {
        if(primeSieve[i] == 1)
        {
            for(int j = 2;i*j < 1000001;++j)
                primeSieve[i*j] = 0;
        }
    }
}

int main()
{

    // intialising boolean array with 1
    for(int i = 1 ; i < 1000001; ++i)
        primeSieve[i] = 1;

    createSieve();
    for(int i = 2;i < 10000001; ++i)
    {
        if(primeSieve[i] == 1)
            primeNumbers[primeCount++] = i;
    }



    int t, n;
    scanf("%d", &t);
    while(t-->0)
    {
        scanf("%d", &n);
        int evenCount = 0, oddCount = 0;
        for(int i = 0;i < primeCount && primeNumbers[i]*primeNumbers[i] <= n ; ++i)
        {
            if(n % primeNumbers[i] == 0)
            {
                int count = 0;
                while(n % primeNumbers[i] == 0)
                {
                    n = n / primeNumbers[i];
                    count++;
                }
                if(count != 0 && count % 2 == 0)
                    evenCount++;
                else
                    oddCount++;
            }


        }
        if( n != 1)
            oddCount++;

        if(evenCount > oddCount)
            printf("Psycho Number\n");
        else
            printf("Ordinary Number\n");
    }
    return 0;

}