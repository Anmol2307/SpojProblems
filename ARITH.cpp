#include <iostream>
#include <cstring>
#include <cmath>
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
			val = (int)(first[diff] - 48) + carry;
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
	
	int space = max (max(size1,size2+1),(int)ans.size());
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
		
		if ((int)(first[size1-j] - 48) > (int)(second[size2-j] - 48) + carry) {
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
			val = (int)(first[diff] - 48) - carry;
			carry = 0;
			ch = (char) (val%10 + 48);
			ans.insert(0,1,ch);
		}
	}
	
	int space = max (max(size1,size2+1),(int)ans.size());
	blank(space - size1);
	cout << first << endl;
	blank(space - (size2+1));
	cout << '-' << second << endl;
	dash(space);
	blank(space - (int)(ans.size()));
	cout << ans << endl;
}

void funmul (string first, string second) {
	cout << first << " " << second << endl;
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
		}
		else if (str.find('-') != string::npos) {
			size_t found = str.find('-');
			funminus(str.substr(0,found),str.substr(found+1,str.size()-found-1));
		}
		else if (str.find('*') != string::npos) {
			size_t found = str.find('*');
			funmul(str.substr(0,found),str.substr(found+1,str.size()-found-1));
		}
	}
}