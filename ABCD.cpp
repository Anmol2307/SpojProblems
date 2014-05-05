#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;




int main  () {

	int n;
	cin >> n;

	string str;
	cin>> str;

	int a, b, c, d;
	a = n - count(str.begin(), str.end(), 'A');
	b = n - count(str.begin(), str.end(), 'B');
	c = n - count(str.begin(), str.end(), 'C');
	d = n - count(str.begin(), str.end(), 'D');

	vector <char> ans(2*n,'X');
	string dummy = "ABCD";
	vector<int> count(4,0);
	count[0] = a;
	count[1] = b;
	count[2] = c;
	count[3] = d;
	
 	int min = min_element(count.begin(), count.end()) - count.begin();
	while(count[min] == 0) {
		dummy.erase(min,1);
		count.erase(count.begin()+min);
		min = min_element(count.begin(), count.end()) - count.begin();
	}
	cout << "HERE " << min << " " << dummy << " " << count[min] << endl;
	for (int i = 0; i < count.size(); i++) {
		cout << count[i] << " ";
	} 
	cout << endl;
	while (dummy != "") {	
 		for (int i = 0 ; i < 2*n && count[min] > 0; i++ ) {
 			if (str[i] != dummy[min] && ans[i] == 'X') {
 				ans[i] = dummy[min];
 				count[min]--;
 			}
 		}
 		dummy.erase(min,1);
		count.erase(count.begin()+min);
		min = min_element(count.begin(), count.end()) - count.begin();
 		cout << "HERE " << min << " " << dummy << " " << count[min] << endl;
 		for (int i = 0; i < count.size(); i++) {
 			cout << count[i] << " ";
 		} 
 		cout << endl;
 	}

	string final;

	for (int i = 0; i < ans.size(); i++) {
		final += ans[i];
	}
	cout << final << endl;

}