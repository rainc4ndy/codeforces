#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	static std::map<char, P> mp = {
		{'N', {0, 1}},
		{'E', {1, 0}},
		{'S', {0, -1}},
		{'W', { -1, 0}}
	};

	vector<char> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	P pos;
	bool flag = false;

	for (int k = 0; k < 100; k++) {
		flag = false;
		for (int i = 0; i < n; i++) {
			auto p = mp[v[i]];
			pos.x += p.x;
			pos.y += p.y;
			if (pos.x == a && pos.y == b) {
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	if (!flag)
		cout << "NO" << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}