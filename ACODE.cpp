#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long int lli;
unsigned long long dp[5001];

long long int find(string str) {

	memset (dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i = 0; i < str.size();i++) {
		if (str[i+1] - '0') dp[i+1] = dp[i];
		int temp = 0;
		temp = (str[i]-'0') * 10;
   		temp += (str[i+1] -'0');
		if (temp <= 26 && temp > 9) {
			dp[i+1] += dp[(i-1) < 0?0:(i-1)];   
		}
	}
	// for (int i = 0; i < str.size(); i++) {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	return dp[str.size()-1];
}


int main () {
	string n;
	while (cin >> n && n != "0"){
		lli ans = find(n);
		cout << ans << endl;
	}
}