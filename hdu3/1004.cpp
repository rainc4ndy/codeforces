#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	string s; string s2;
	cin >> s >> s2;

	if (s2.size() >= 3 && s2 != "100") {
		set<char> ss;
		for (int i = 0; i < s.size(); i++) {
			ss.insert(s[i]);
		}
		cout << ss.size() << endl;
	} else {
		int n = atoi(s2.c_str());

		string r;
		for (int i =0; i < n; i++) r+=s;

		vector<int> dp(r.size(), 1); 
		int maxLength = 1;

		for (int i = 1; i < r.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (r[i] > r[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			maxLength = max(maxLength, dp[i]);
		}
		cout << maxLength << endl;
	}

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