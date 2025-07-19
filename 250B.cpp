#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;
#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"
#define debug(x) cout << #x << ' ' << x << endl;
#define debug1(x)                     \
    RED;                              \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug2(x)                     \
    GREEN;                            \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug3(x)                     \
    BLUE;                             \
    cout << #x << ' ' << x << endl; \
    RESET;

void solve() {
	string s;
	cin >> s;

	vector<string> bks;
	int pos = 0;
	while ((pos = s.find(":")) != string::npos) {
		bks.eb(s.substr(0, pos));
		s.erase(0, pos + 1);
	}
	bks.eb(s);

	int cnt = 0;
	for (auto& it : bks) {
		if (!it.size())
			continue;
		stringstream ss;
		ss << setfill('0') << setw(4) << it;
		it = ss.str();
		cnt++;
	}

	int now = 0;
	bool worked = false;
	for (int i = 0; i < bks.size(); i++) {
		if (now >= 8) {
			break;
		}
		if (!bks[i].size() ) {
			if (!worked) {
				int k = 8 - cnt;
				for (int j = 0; j < k; j++) {
					now++;
					cout << "0000";
					if (now < 8) {
						cout << ':';
					}
				}
				worked = true;
			}
		}
		else {
			now++;
			cout << bks[i];
			if (now < 8) {
				cout << ':';
			}
		}
	}
	cout << endl;
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}