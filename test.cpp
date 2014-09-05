#include <iostream>
#include <cstdio>
#include <list>
#include <queue>
#include <cstring>
#include <algorithm>
#include <time.h>
#define maxn 100000
using namespace std;
 
typedef long long LL;
 
char s[100005];
int n;
 
LL mod = 1000000007;
LL memo[100005][3][2];
 
LL dp (int index, int modValue,int tight)
{
    LL &res = memo[index][modValue][tight];
    // if res is not equal to -1, then just return it.
    if (res == -1)
    {
        res = 0;
        if (index == n)
        {
            // we are constructing the values from left to right,
            // means everytime we are taking some number for every index going from left to right,
            // in this way our number is getting constructed.
            // !tight means less than value of s.
            // modValue should be zero. As we need the number to be 0 mod 3.
            if (!tight & modValue == 0)
                res = 1;
        }
        else
        {
            // if number constructed upto now is same as the number S taken upto digit index.
            if (tight)
            {
                for (int i = 0; i <= s[index] - '0'; i++)
                {
                    if (i == s[index] - '0')
                    {
                        // value is still equal. Hence it is stil tight.
                        res += dp (index + 1, (modValue + i * i) % 3, 1);
                        res %= mod;
                    }
                    else
                    {
                        // value becomes less so it is not tight, tight becomes false.
                        res += dp (index + 1, (modValue + i * i) % 3, 0);
                        res %= mod;
                    }
                }
            }
            else
            {
                // if already tight is false, then you can take any number in this index, as it is already
                // less.
                for (int i = 0; i < 10; i++)
                {
                    // it is already not tight, so not going to be tight again.
                    res += dp (index + 1, (modValue + i * i) % 3, 0);
                    res %= mod;
                }
            }
        }
    }
 
    return res;
}
 
int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int T;
    scanf ("%d", &T);
    while (T--)
    {
        scanf ("%s", &s);
        n = strlen (s);
 
        memset (memo, -1, sizeof(memo));
 
        LL ans = dp (0 , 0, 1);
 
        printf ("%d\n", ans);
    }
 
    return 0;
}