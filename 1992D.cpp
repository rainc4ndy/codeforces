#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200010;
char v[MAX_N];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	int cur = 0;
	int swimDistance = 0;
	int last = 'L';

	while (cur < n + 1) {
		
		bool jumped = false;
		if (last == 'L') {
			if (cur + m >= n + 1) {
				cout << "YES" << endl;
				return;
			}
			for (int i = cur + m; i > cur; --i) {
				if (v[i] == 'L') {
					cur = i;
					last = v[i];
					jumped = true;
					break;
				}
			}
		}

		if (!jumped) {
			//jump into the water?
			if (last == 'L') {
				for (int i = cur + m; i > cur; --i) {
					if (v[i] == 'W') {
						cur = i;
						last = v[i];
						jumped = true;
						break;
					}
				}
				//cannot jump into water
				if (!jumped) {
					cout << "NO" << endl;
					return;
				}
			} else {
				if (v[cur + 1] == 'C') {
					cout << "NO" << endl;
					return;
				}

				if (last == 'W') {
					if (swimDistance + 1 > k) {
						cout << "NO" << endl;
						return;
					}
					swimDistance++;
				}
				
				cur++;
				last = v[cur];
			}
		}
	}

	cout << "YES" << endl;
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