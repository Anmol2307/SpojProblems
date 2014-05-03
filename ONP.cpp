#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main () {


	int t;
	cin>>t;
	string operators = "+-*/^";
	while (t--) {
		string str;
		cin>>str;
		string ans;
		queue<char> output;
		stack<char> stk;
		
		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if (ch == '(') {
				stk.push(ch);
			}
			else if (ch == ')') {
				while (stk.top() != '(') {
					output.push(stk.top());
					stk.pop();
				}
				stk.pop();
			}
			else if (operators.find(ch) != string::npos) {
				while (stk.size() > 0 && operators.find(stk.top()) != string::npos && operators.find(ch) <= operators.find(stk.top())) {
					output.push(stk.top());
					stk.pop();
				}
				stk.push(ch);
			}
			else {
				output.push(ch);
			}
		}
		while (!stk.empty()) {
			output.push(stk.top());
			stk.pop();
		}
		while (!output.empty()) {
			ans += output.front();
			output.pop();
		}
		cout << ans << endl;
	}	

}