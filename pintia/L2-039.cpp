#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef pair<vector<int>, int> P;

bool cmp(P&a, P&b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

map<vector<int>, int> um;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	cin.ignore();
	vector<int> v;
	int tmp;
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		um[v]++;
	}

	vector<P> ans;
	for (auto it :um) {
		ans.push_back(it);
	}
	sort(ans.begin(), ans.end(), cmp);

	cout << um.size() << endl;
	for (int i = 0; i < um.size(); i++) {
		cout << ans[i].second << ' ';
		for (int j = 0; j < ans[i].first.size(); j++) {
			cout << ans[i].first[j];
			if (j != ans[i].first.size()-1)
				cout << ' ';
		}
		if (i != um.size() -1)
			cout << endl;
	}

	return 0;
}