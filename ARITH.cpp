#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

void blank (int num) {
	for (int i = 0; i < num; i++) {
		cout << " ";
	}
}

void dash (int num) {
	for (int i = 0; i < num; i++) {
		cout << '-';
	}
	cout << endl;
}

void funplus(string first, string second) {
	int size1 = first.size();
	int size2 = second.size();
	int carry = 0;
	string ans = "";
	char ch;int val;
	
	for (int j = 1; j <= min(size1, size2); j++) {
		val = (int)(first[size1-j] - 48) + (int)(second[size2-j] - 48) + carry;
		carry = val/10;
		ch = (char)(val%10 + 48);
		ans.insert(0,1,ch);
	}

	int diff = abs(size2 - size1);
	if (size1 < size2) {
		while (diff--) {
			val = (int)(second[diff] - 48) + carry;
			carry = val/10;
			ch = (char) (val%10 + 48);
			ans.insert(0,1,ch);
		}
	}
	else if (size2 < size1) {
		while(diff--){
			val = (int)(first[diff 	] - 48) + carry;
			carry = val/10;
			ch = (char) (val%10 + 48);
			ans.insert(0,1,ch);
		}
	}
	if (carry != 0) {
		ch = (char)(carry + 48);
		ans.insert(0,1,ch);
	}
	
	int space = max (size2+1,(int)ans.size());
	blank(space - size1);
	cout << first << endl;
	blank(space - (size2+1));
	cout << '+' << second << endl;
	dash(space);
	blank(space - (int)(ans.size()));
	cout << ans << endl;
}

void funminus (string first, string second) {
	int size1 = first.size();
	int size2 = second.size();
	int carry = 0;
	string ans = "";
	char ch;int val;
	
	for (int j = 1; j <= size2; j++) {
		
		if ((int)(first[size1-j] - 48) >= (int)(second[size2-j] - 48) + carry) {
			val = (int)(first[size1-j] - 48) - (int)(second[size2-j] - 48) - carry;	
			carry = 0;
		}
		else {
			val = (int)(first[size1-j] - 48) + 10 - (int)(second[size2-j] - 48) - carry;	
			carry = 1;
		}

		ch = (char)(val%10 + 48);
		ans.insert(0,1,ch);
	}

	int diff = abs(size2 - size1);
	if (size2 < size1) {
		while(diff--){
			if ((int)(first[diff] - 48) >= carry) {
				val = (int)(first[diff] - 48) - carry;
				carry = 0;
			}
			else {
				val = (int)(first[diff] - 48) + 10 - carry;
				carry = 1;
			}
			ch = (char) (val%10 + 48);
			ans.insert(0,1,ch);
		}
	}
	
	while(ans[0] == '0') {
		ans.erase(0,1);
	}

	if (ans == "") ans = "0";

	int space = max (size2+1,(int)ans.size());
	int y = max (max (size1,size2+1),(int)ans.size());
	blank(space - size1);
	cout << first << endl;
	blank(y - (size2+1));
	cout << '-' << second << endl;
	blank(y - space);
	dash(space);
	blank(y - (int)(ans.size()));
	cout << ans << endl;
}

	
string singlemul (string first, char second ) {
	int size = first.size();
	int carry = 0;
	int val;char ch; string ans;
	if (second == '0') {
		ans = "0";
		return ans;
	}
	
	for (int i = 1; i <= size; i++) {
		val = (int)(first[size-i] - 48) * (int)(second - 48) + carry;
		carry = val/10;
		ch = (char) (val%10 + 48);
		ans.insert(0,1,ch);
	}
	if (carry != 0) ans.insert(0,1,(char)(carry+48));
	return ans;
}

string finaladd(vector<string> vec) {
	int carry = 0;
	int size = vec[0].size();
	string ans;
	for (int i = 1; i <= size; i++) {		
		int sum = 0;
		for (int j = 0; j < vec.size(); j++) {
			sum += (int)(vec[j][size-i] - 48);
		}
		sum += carry;
		carry = sum/10;
		ans.insert(0,1,(char)(sum%10 + 48));
	}
	stringstream ss;
	ss << carry;
	string str = ss.str();
	if (carry != 0) ans.insert(0,str);
	
	while(ans[0] == '0') {
		ans.erase(0,1);
	}

	if (ans == "") ans = "0";
	
	return ans;
}


void funmul (string first, string second) {
	int size1 = first.size();
	int size2 = second.size();
	int carry = 0;
	string ans = "";
	char ch;int val;
	vector<string> mulans;
	vector<int> num;
	int m = 0;

	for (int j = 1; j <= size2; j++) {
		ans = singlemul(first, second[size2-j]);
		mulans.push_back(ans);
		num.push_back(ans.size() + j -1);
		if (ans.size() + j -1 > m) m = ans.size() + j -1;
	}

	int space = max(max(size1,size2+1),m);
	blank(space - size1);
	cout << first << endl;
	blank(space - (size2+1));
	cout << '*' << second << endl;
	blank(space - max(size2+1,(int)mulans[0].size()));
	dash(max(size2+1,(int)mulans[0].size()));
	
	if (second.size() == 1) {
		ans = singlemul(first,second[0]);
		blank(space - (int)(ans.size()));
		cout << ans <<endl;
		return;
	}

	for (int i = 0; i < mulans.size(); i++) {
		blank(space - num[i]);
		cout << mulans[i] << endl;

	}
	for (int i = 0; i < mulans.size(); i++) {
		string x = mulans[i];
		x.append(num[i] - mulans[i].size(),'0');
		x.insert(0,space-num[i],'0');
		mulans[i] = x;
	}

	string final = finaladd(mulans);
	blank(space - max(num[num.size()-1],(int)(final.size())));
	dash(max(num[num.size()-1],(int)(final.size())));
	blank(space - (int)(final.size()));
	cout << final << endl;
}

int main () {
	int t;
	cin>>t;

	while (t--) {
		string str;
		cin>>str;

		if (str.find('+') != string::npos) {
			size_t found = str.find('+');
			funplus(str.substr(0,found),str.substr(found+1,str.size()-found-1));
			cout << endl;
		}
		else if (str.find('-') != string::npos) {
			size_t found = str.find('-');
			funminus(str.substr(0,found),str.substr(found+1,str.size()-found-1));
			cout << endl;
		}
		else if (str.find('*') != string::npos) {
			size_t found = str.find('*');
			funmul(str.substr(0,found),str.substr(found+1,str.size()-found-1));
			cout << endl;
		}
	}
}