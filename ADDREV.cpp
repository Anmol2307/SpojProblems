#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main () {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;

		cin >> x >> y;
		int total = 0;
		vector <int> first;
		vector <int> second;
		vector <int> ans;
	
		while (x != 0) {
			first.push_back(x%10);
			x = x/10;
		}
		while (y != 0) {
			second.push_back(y%10);
			y = y/10;
		}
		reverse(first.begin(),first.end());
		reverse(second.begin(),second.end());
		int ptr1 = 0;
		int ptr2 = 0;
		int carry = 0;
		while (ptr1 < first.size() && ptr2 < second.size()) {
			ans.push_back((first[ptr1] + second[ptr2] + carry)%10);
			carry = (first[ptr1] + second[ptr2] + carry)/10;
			ptr1++;  ptr2++;
		}

		while (ptr1 < first.size()) {
			ans.push_back((first[ptr1] + carry)%10);
			carry = (first[ptr1] + carry)/10;
			ptr1++;
		}
		while (ptr2 < second.size()) {
			ans.push_back((second[ptr2] + carry)%10);
			carry = (second[ptr2] + carry)/10;
			ptr2++;
		}
		if (carry != 0 ) ans.push_back(carry);
		reverse (ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			total += ans[i] * pow(10,i);
		}
		cout << total << endl;
	}

}