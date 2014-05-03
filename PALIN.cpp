#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main () {

	int t;
	cin>>t;

	while (t--) {
		string str;
		string finstr;
		cin>>str;
		finstr = str;
		int len = str.size(); 
		int flag = 1;

		for (int i = 0; i < len; i++) {
			if (str[i] != '9') {
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			finstr = "";
			finstr.push_back('1');
			for (int j = 1; j < len; j++) {
				finstr.push_back('0');
			}
			finstr.push_back('1');
			cout << finstr << endl;
			continue;
		}

		flag = 0;
		
		for (int i =0 ; i < len/2 ; i++) {
			if (str[i] < str[len-i-1]) flag = -1;
			else if (str[i] > str[len-i-1]) flag = 1;
			finstr[len-i-1] = str[i];
		}

		if (flag == -1 || flag == 0) {
			int t = 0;
			int tmp1;
			if(len%2 == 0)
				tmp1 = len/2-1;
			else
				tmp1 = len/2;
			while(str[tmp1-t] == '9')
			{
				finstr[tmp1-t] = '0';
				finstr[len-1-tmp1+t] = '0';
				t ++;
			}
			finstr[tmp1-t] ++;
			finstr[len-1-tmp1+t] = finstr[tmp1-t];
		}

		cout << finstr << endl;
	}
}