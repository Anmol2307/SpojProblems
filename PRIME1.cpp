#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int main () {
	int t;
	cin>>t;
	while (t--) {
		int m, n;
		cin>>m>>n;
		vector<bool> vec(n+1,1);
		vec[1] = 0;

		for (int i = 2 ; i <=sqrt(n); i++) {
			if (vec[i]) {
				for (int j = i*i; j <=n; j+=i) {
					vec[j] = 0;
				}
			}
		}

		for (int i = m; i <=n; i++) {
			if (vec[i]) cout << i << endl;
		}

		cout << endl;	
	}
}