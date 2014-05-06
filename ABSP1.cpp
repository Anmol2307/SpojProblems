	#include <iostream>
	#include <vector>
	#include <cstdlib>
	using namespace std;

	int main () {

		int t;
		cin>>t;
		while (t--) {
			int n;
			cin>>n;
			vector<int> vec;
			vector<int> diff;
			vector<long long> sum;
			long long int tot;
			for (int i = 0; i < n; i++) {
				int x;
				cin>>x;
				//if (sz == 0) vec.push_back(x);
				//else if (sz != 0 && x != vec[sz-1]) {
				vec.push_back(x);
				int sz = vec.size();
				if (sz > 1) {
					diff.push_back(vec[sz-1] - vec[sz-2]);
					int dsz = diff.size();
					if (dsz == 1){
						sum.push_back(diff[0]);
						tot = sum[0];
					}
					else if (dsz > 1){
						sum.push_back(diff[dsz-1] + sum[sum.size()-1]);
						tot += sum[sum.size()-1];
					}
				}
				//}
			}

			long long int ans = tot;
			int dsz = diff.size();
			if (dsz > 0) {
				long long dum = -1* diff[0]*(dsz);
				for (int i = 1 ; i < diff.size(); i++){
					ans += tot + dum;
					dum -=  diff[i]*(dsz - i);
				}
			}
			else {
				ans = 0;
			}
			
			cout << ans << endl;
		}
	}