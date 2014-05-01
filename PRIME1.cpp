//Sieve of Eratosthenes

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>


using namespace std;

int main () {

	vector <int> primes;
	primes.push_back(2);

	for (int i = 3; i <= 32118; i++) {
		int val = sqrt(i) + 1;
		bool is_prime = true;
		for (int j = 0; j < primes.size(); j++) {
			if (primes[j] > val) break;
			if (i%primes[j] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) primes.push_back(i);	
	}

	int t;
	cin>>t;
	while (t--) {

		int m, n;
		cin>>m>>n;
		
		for (int i = m ; i <= n; i++) {
			if (i==1) continue;
			int k = sqrt(i);
			bool pr = true;
			for (int j = 0; primes[j] <= k; j++) {
				if (i%primes[j] == 0){
					pr = false;
					break;
				}
			}
			if (pr) cout << i << endl;
		}

		cout << endl;	
	}

}