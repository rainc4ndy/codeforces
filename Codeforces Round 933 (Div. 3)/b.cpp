#include <bits/stdc++.h>
using namespace std;

#define mod (200001)
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	int n;
	ll v[mod];

	vector<bool> ans(t);
	bool flag = false;
	int a, b,c;
	ll mx, sum;
	for(unsigned i = 0; i < t; ++i) {
		cin >> n;
		mx =0; sum =0;
		for(unsigned j = 0; j < n; ++j) {
			cin >> v[j];
			mx = max(v[j], mx);
			sum += v[j];
		}
		flag = true;
		if (mx > sum - mx) {
			ans[i] = false;
			continue;
		}
		if (abs(v[0] - v[n-1]) > 2) {
			ans[i] = false;
			continue;
		}
		for(unsigned j = 0; j < n - 2; ++j) {
			a = v[j];
			b = v[j+1];
			c = v[j+2];

			if (abs(b-a) < 2 && abs(b-c) < 2) {
				flag = false;
				break;
			}
		}
		ans[i] = flag;
	}

	for(unsigned i = 0; i < t; ++i) {
		cout << (ans[i] ? "YES" : "NO");
		if (i != t-1)
			cout << endl;
	}

	return 0;
}
