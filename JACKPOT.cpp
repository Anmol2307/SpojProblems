#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


static int arr[1000000001];
static bool marked[1000000001] = {0};

	
void preprocess () {
	//memset(marked,0,sizeof(marked));
	arr[1] = 0;
	marked[1] = 1;
	
	for (int i = 2; i < 1000000001; i++) {
		if (!marked[i]) {
			arr[i] = arr[i-1] + 1;
			marked[i] = 1;
			int j = i;
			while (j <= 100) {
				arr[j*2] = arr[j] + 1;
				marked[j*2] = 1;
				j *= 2;
			}
		}
	}
}


int main() {
	
	int t;
	cin >> t;

	while (t--) {
		int n ;
		cin >> n;
		int x = 1;
		int a,b,dummy;
		int ans = 1000000001;
		bool flag = false;
		while ((pow(2,x) -1) < n) {
			a = n && (pow(2,x) -1);
			b = n - a;
			if (a != 0 && b != 0) {
				dummy = arr[a] + arr[b];
				if (dummy < ans) ans = dummy;
				flag = true;
			}
			x++;
		}
		if (!flag) {
			ans = pow(2,x-1);
		}
		cout << ans << endl;	
	}

}