#include <bits/stdc++.h>
#include <cwchar>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

#define int ll

class MyTree {
public:

	vector<int> v;
	int sz;
	MyTree(int sz) {
		this->sz = sz;
		v.resize(sz + 1);
	}

	int lowbit(int x) {
		return x & (-x);
	}
	void add(int x, int value) {
		while (x <= sz) {
			v[x] += value;
			x += lowbit(x);
		}
	}

	int query(int x) {
		int sum = 0;
		while (x > 0) {
			sum += v[x];
			x -= lowbit(x);
		}
		return sum;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	MyTree t1(n), t2(n);
	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		t1.add(i, v[i] - v[i - 1]);
		t2.add(i, (i - 1)*(v[i] - v[i - 1]));
	}

	auto range_query = [&](int x) {
		return x * t1.query(x) - t2.query(x);
	};

	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			t1.add(b, d), t1.add(c + 1, -d);
			t2.add(b, (b - 1)*d), t2.add(c + 1, -c * d);
		} else {
			cin >> b >> c;
			cout << range_query(c) - range_query(b - 1) << endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();

	return 0;
}