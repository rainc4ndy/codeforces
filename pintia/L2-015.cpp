#include <bits/stdc++.h>
using namespace std;

#define INF (0x3f3f3f3f)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, k, m;

	cin >> n >> k >> m;
	vector<double> ans(n, 0);

	int mx, mi, sum, x;
	for(int i = 0; i < n; ++i) {
		mx = -1;
		mi = 110;
		sum = 0;
		for(int j = 0; j < k; ++j) {
			cin >> x;
			sum += x;
			mi = min(mi, x);
			mx = max(mx, x);
		}
		sum -= mx + mi;
		ans[i] = (double)sum / (k-2.0);
	}
	sort(ans.begin(), ans.end());
	for(int i = n-m; i < n; ++i) {
		cout << setprecision(3) << fixed << ans[i];
		if (i !=n-1)
			cout <<' ';
	}

	return 0;
}
