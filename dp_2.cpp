#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n, m, k, p;
	cin >> n >> m >> k >> p;

	vector<vector<ll>> mem(n + 1, vector<ll>(k + 1, -1));
	auto dfs = [&](const auto & self, ll start, ll step) -> ll {
		if (mem[start][step] != -1)
			return mem[start][step];
		ll res = 0;
		if (step == 0) {
			if (start == p) {
				res = 1;
			} else {
				res = 0;
			}
		} else {
			if (start == 1)
				res = (res + self(self, start + 1, step - 1)) % mod;
			else if (start == n)
				res = (res + self(self, start - 1, step - 1)) % mod;
			else {
				res = (self(self, start - 1, step - 1)
					 + self(self, start + 1, step - 1)) % mod;
			}
		}
		return mem[start][step] = res;
	};

	cout << dfs(dfs, m, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	//cin >> _;
	while (_--) solve();

	return 0;
}