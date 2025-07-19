#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 3221225473;  // 3 * 2^30 + 1

ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<bool> visited(n + 1, false);
	ll result = 1;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int cycle_length = 0;
			int x = i;

			while (!visited[x]) {
				visited[x] = true;
				x = A[x - 1];  // 跳转到 A[x] 位置
				cycle_length++;
			}

			result = lcm(result, cycle_length) % MOD;  // 更新 LCM
		}
	}
	cout << result << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
