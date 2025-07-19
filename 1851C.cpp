#include <bits/stdc++.h>
using namespace std;

#define mod (200001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int cnt = 1;
	int trg = v[0];

	int loc;
	bool ok = false;

	if (cnt >= k) {
		trg = v[n - 1];
		loc = 0;

		ok = true;
	} else {
		for (int i = 1; i < n; i++) {
			if (v[i] == trg) {
				cnt++;
				if (cnt >= k) {
					trg = v[n - 1];
					loc = i;

					ok = true;
					break;
				}
			}
		}
	}

	if (!ok) {
		cout << "NO" << endl;
		return;
	}

	//cout << "loc = " << loc << endl;
	cnt = 1;
	for (int i = n - 1; i >= loc; i--) {
		if (v[i] == trg) {
			cnt++;
			if (cnt >= k) {
				cout << "YES" << endl;
				return;
			}
		}
	}

	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}