#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ull unsigned long long

ull v[mod] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	ull t; 
	cin >> t;

	ull n,k;
	vector<ull> ans(t);

	ull cnt, sum, s2;

	int low, high;
	bool flag = false;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		s2  =0;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			s2 += v[j];
		}

		low = 0;
		high = n-1;

		cnt = 0;
		sum = 0;

		if (s2 <= k) {
			ans[i] = n;
			continue;
		}

		while (sum <= k) {
			if (flag) {
				sum += v[low++];
			} else {
				sum += v[high--];
			}
			flag ^= 1;
			if (sum <= k) 
				cnt++;
		}

		ans[i] = cnt;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t -1)
			cout << endl;
	}

 	return 0;
}