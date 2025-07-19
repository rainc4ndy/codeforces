#include <bits/stdc++.h>
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
const int maxn = 1e7 + 10;
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

int ans = 0;
int nex[maxn][26];
vector<bool> exist(maxn);
vector<bool> exist_2(maxn);
vector<bool> bad(maxn);
int sz[maxn];
int cnt;

struct trie {
	void insert(char *s, int l) {
		int p = 0;
		bool ok = true;
		for (int i = 0; i < l; i++) {
			int c = s[i] - 'a';
			if (!nex[p][c]) nex[p][c] = ++cnt;
			p = nex[p][c];
			sz[p]++;
			if (bad[p]) ok = false;
		}
		exist[p] = true;
		if (ok) ans++;
	}

	void insert_prefix(char *s, int l) {
		int p = 0;
		vector<int> vv;
		for (int i = 0; i < l; i++) {
			int c = s[i] - 'a';
			if (!nex[p][c]) nex[p][c] = ++cnt;
			p = nex[p][c];
			vv.eb(p);
		}
		if (!bad[p]) {
			bad[p] = true;
			ans -= sz[p];
			for (auto it : vv) if (sz[it]) sz[it]--;
		}
	}

	bool find(char *s, int l) {
		int p = 0;
		for (int i = 0; i < l; i++) {
			int c = s[i] - 'a';
			if (!nex[p][c]) return 0;
			p = nex[p][c];
		}
		return exist[p];
	}
};


void solve() {
	ll q;
	cin >> q;

	trie t;
	for (int i = 0; i < q; i++) {
		int x;
		string s;
		cin >> x;
		cin >> s;

		if (x == 1) {
			t.insert_prefix(s.data(), s.size());
		} else if (x == 2) {
			t.insert(s.data(), s.size());
		}
		cout << ans << endl;
	}
}

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}