#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() { // code
	int n;
	cin >> n;
	n -= 2;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		if (v[i] == 1) {
			if (i + 2 < n) {
				if (v[i + 2] == 1) {
					if (v[i + 1] == 0) {
						cout << "NO" << endl;
						return;
					}
				}
			}
		}
	}
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _;
	cin >> _;
	while (_--)
		solve();

	return 0;
}