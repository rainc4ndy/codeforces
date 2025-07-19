#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n;
	vector<long long > ans(t);
	vector<long long > v;
	for (unsigned i = 0; i < t; ++i) {
		cin >> n;
		v.resize(n);
		for (unsigned j = 0; j < n; ++j) {
			cin >> v[j];
		}
		sort(v.begin(), v.end(), greater<long long>());

		ans[i] = 2 * (v[0] + v[1] - v[v.size()-1] - v[v.size()-2]);
	}

	for (unsigned i = 0; i < t; ++i) {
		cout << ans[i] ;
		if (i != n)
			cout << endl;
	}

	return 0;
}
