#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	int n;

	vector<int> ans(t);
	vector<int> v;

	map<int, int> s;

	int matched, fp;
	for (int i = 0; i < t; i++) {
		cin >> n;
		v.resize(n);

		s.clear();
		matched = 0;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			s[v[j]]++;
		}

		for (int j = 0; j < n; j++) {
			fp = numeric_limits<int>().max() - v[j];
			if (s.count(fp)) {
				matched++;
				s[v[j]]--;
				s[fp]--;
			}
			//matched += s.count(fp);
		}

		ans[i] = n - matched / 2;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}