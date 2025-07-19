#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, tmp;
	cin >> t;

	vector<int> ans(t);
	unordered_map<unsigned int, unsigned int> m;

	int matched, extra;
	unsigned int pp = (1u << 31) - 1;

	for (int i = 0; i < t; i++) {
		cin >> n;

		m.clear();
		matched = 0;
		extra = 0;

		for (int j = 0; j < n; j++) {
			cin >> tmp;
			m[tmp]++;
		}

		for (auto it : m) {
			unsigned int ib = pp&(~it.first);
			if (m[ib] > 0) {
				matched += max(m[ib], it.second);
				m[ib] = 0;
			} else {
				matched++;
			}
		}
		
		cout << "matched = " << matched << endl;
		cout << "extra = " << extra << endl;

		ans[i] = matched;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}