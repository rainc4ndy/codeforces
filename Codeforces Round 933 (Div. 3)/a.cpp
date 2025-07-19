#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m, k;
	cin >> t;

	vector<int> ans(t);

	vector<int> v1(101), v2(101);
	for (unsigned i = 0; i < t; ++i) {
		cin >> n >> m >> k;

		for (unsigned j = 0; j < n; ++j) {
			cin >> v1[j];
		}
		for (unsigned j = 0; j < m; ++j) {
			cin >> v2[j];
			for (unsigned x = 0; x < n; ++x) {
				if (v1[x] + v2[j] <= k) {
					ans[i]++;
				}
			}
		}

	}

	for (unsigned i = 0; i < t; ++i) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}
