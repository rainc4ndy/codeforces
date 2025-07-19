#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n;
	cin >> n;
	vector<P> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i].x;
	for (int i = 0; i < n; i++)
		cin >> v[i].y;

	int sum = 0;
	int need = 0;
	int res = 1e9;
	bool flag = false;  // 至多只能有一种缺失的材料
	for (int i = 0; i < n; i++) {
		if (v[i].x < v[i].y) {
			if (flag) {
				cout << "NO" << endl;
				return;
			}
			flag = true;
			need = v[i].y - v[i].x;
		} else {
			res = min(res, v[i].x - v[i].y);
		}
	}
	cout << ((res >= need) ? "YES" : "NO") << endl;
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