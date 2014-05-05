#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
#define MAX 1000000

vector <int> primes;
vector <int> isprime(4*MAX,1);
vector <int> knum;

void sieve() {

	isprime[0]=0;
	isprime[1]=0;
	for (int i = 0; i*i < 4*MAX; i++) {
		if (isprime[i]) {
			for (int j = i*i; j < 4*MAX; j+=i) {
				isprime[j] = 0;
			}
		}
	}
	for (int i = 0; i < 4*MAX; i++) {
		if (isprime[i]) primes.push_back(i);
	}
}

int pow1(int x, int n){
	if(n==0) return 1;
	int r = pow1(x, n/2);
	r=r*r;
	if(n%2==1)
		r=r*x;
	return r;
}

int solve(int num) {
	int result = 1;
	if(isprime[num])
		return num+1;
	for (int i = 0; i < primes.size() && primes[i] < num; i++) {
		int count = 0;
		while (num%primes[i] == 0) {
			num = num/primes[i];
			count++;
		}
		if (count) {
			result = result * (pow1(primes[i],count+1) - 1)/(primes[i]-1);
		}
	}
	return result;
}


int main () {

	sieve();
	knum.push_back(2);
	for(int i=1;i*i<=MAX;i++){
		int k = solve(i*i);
		if(isprime[k])
			knum.push_back(i*i);
	}

	int t;
	cin>>t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int ai=0,bi=0;
		while(knum[ai++]<a);
        while(knum[bi++]<b);
        cout<<bi-ai<<endl;  

	}

}