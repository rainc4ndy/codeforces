#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define mod (200001)
#define ll long long

int va[mod] {}, vb[mod] {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m;
	int k;

	cin >> t;

	int cnt = 0;
	unordered_map<int, int> us; //b num
	unordered_map<int, int> mark;
	int low, high;

	vector<int> ans(t);
	for (int i = 0 ; i < t ; i++) {

		cnt = 0;
		us.clear();
		cin >> n >> m >> k;

		for (int j = 0; j < n; j++)
			cin >> va[j];
		for (int j = 0; j < m; j++) {

			cin >> vb[j];
			us[vb[j]]++;
		}

		low = 0;
		high = m;

		//在a取m区间，至少有k个匹配，且只记录元素一次
		//cout << "case " << i  << ": ";
		bool flag;

		while (high <= n) {
			cnt = 0;
			mark.clear();
			flag = true;

			for (int j = low; j < high; j++) {
				if (us.count(va[j])) {
					mark[va[j]]++;
				}
			}

			if (mark.size() >= k) {
				for (auto it :mark) {
					if (it.second < us[it.first]) {
						flag = false;
					}
				}
				if (flag)
					ans[i]++;
			}

			low++;
			high++;
		}

	}

	for (int i = 0 ; i < t; i++) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}