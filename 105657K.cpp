#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		ll n, m, k;
		cin >> n >> m >> k;
		ll N = n * m;
		vector<ll> p(N + 1);
		for (ll i = 1; i <= N; i++) {
			ll x;
			cin >> x;
			p[x] = i - 1;
		}
		ll answer = LLONG_MAX;
		for (ll i = 0; i < n; i++) {
			vector<ll> idx;
			idx.reserve(m);
			ll base = i * m;
			for (ll j = 1; j <= m; j++) {
				idx.push_back(p[base + j]);
			}
			sort(idx.begin(), idx.end());
			ll bi;
			if (k >= m) {
				bi = m;
			} else {
				// 去掉最大的 k 个，剩下那个最晚完成的在 idx[m-k-1]
				bi = max(m, idx[m - k - 1] + 1);
			}
			answer = min(answer, bi);
		}
		cout << answer << '\n';
	}
	return 0;
}
