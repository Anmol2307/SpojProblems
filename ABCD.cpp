#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string find(string val) {
	string tot = "ABCD";
	tot.erase(remove(tot.begin(), tot.end(), val[0]), tot.end());
	tot.erase(remove(tot.begin(), tot.end(), val[1]), tot.end());
	return tot;
}

int main () {

	int n;
	cin>>n;
	string str;
	cin>>str;
	string ans = "";
	for (int i = 0; i < str.size(); i+=2) {
		string dummy1 = "";
		dummy1 += str[i];
		dummy1 += str[i+1];
		
		string ret = find(dummy1);
		
		if (ans != "" && ans[ans.size()-1] == ret[0]){
			char ch = ret[0];
			ret[0] = ret[1];
			ret[1] = ch;
		}
		ans += ret;
	}
	cout << ans << endl;
}