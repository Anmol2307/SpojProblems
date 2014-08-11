#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
 
typedef unsigned long long LL;
 
int prime[100];
const LL INF = (LL) 1e19;
 
LL memo[65][65][2];
vector <int> a;
 
LL dp (int index, int sum, int tight) {
    LL &res = memo[index][sum][tight];
    if (res == -1) {
        res = 0;
        if (index == a.size()) {
            if (prime[sum])
                res = 1;
        }
        else {
            if (tight) {
                for (int i = 0; i <= a[index]; i++) {
                    if (i == a[index]) {
                        res += dp (index + 1, sum + i, tight);
                    } else {
                        res += dp (index + 1, sum + i, false);
                    }
                }
            } 
            else {
                for (int i = 0; i < 2; i++) {
                    res += dp (index + 1, sum + i, false);
                }
            }
        }
    }
    return res;
}
 
LL solve (LL n) {
    if (n == 0)
        return 0;
 
    a.clear();
    while (n) {
        a.push_back (n % 2);
        n /= 2;
    }
    reverse (a.begin(), a.end());
 
    memset (memo, -1, sizeof (memo));
    LL ans = dp (0, 0, 1);
    return ans;
}
 
LL digit_sum (LL n) {
    LL ans = 0;
    while (n) {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}
 
LL brute (LL a, LL b) {
    LL ans = 0;
    for (LL i = a; i <= b; i++) {
        if (prime [digit_sum (i)]) {
            ans ++;
        }
    }
    return ans;
}
 
int isPrime (int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
void pre () {
    for (int i = 2; i < 100; i++) {
        prime[i] = isPrime (i);
    }
}
 
int main() {
    pre();
    LL a, b;
    int T;
    cin >> T;
    assert (T >= 1 && T <= 100000);
    while (T--) {
        cin >> a >> b;
        assert (a <= b);
        assert (a >= 1 && a <= INF);
        assert (b >= 1 && b <= INF);
 
        LL ans = solve (b) - solve (a - 1);
        /*
        if (b - a <= 10000) {
            LL ans1 = brute (a, b);
            assert (ans == ans1);
        }
        */
        cout << ans << endl;
    }
    return 0;
}