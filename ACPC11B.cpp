#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main () {

	int t;
	cin>>t;
	while (t--) {
		int n1,n2;
		cin>>n1;
		vector <int> first;
		vector <int> second;
		for (int i = 0; i < n1; i++) {
			int x;
			cin>>x;
			first.push_back(x);
		}
		cin >> n2;
		for (int i = 0; i < n2; i++) {
			int x;
			cin>>x;
			second.push_back(x);
		}

		sort(first.begin(),first.end());
		sort(second.begin(),second.end());
		int pt1 = 0;
		int pt2 = 0;
		int min = 1000000;
		while ((pt1 < n1) && (pt2 < n2)) {
			if (first[pt1] <= second[pt2]) {
				if (min > (second[pt2] - first[pt1])) min = second[pt2] - first[pt1]; 
				pt1++;
			}
			else {
				if (min > (first[pt1] - second[pt2])) min = first[pt1] - second[pt2]; 
				pt2++;
			}
		}
		cout << min << endl;		
	}
}	