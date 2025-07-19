#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define setdb(v) setprecision(v)
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define nin ll n; cin >> n
inline void read(int &a) { cin >> a; }
inline void read(ll &a) { cin >> a; }
inline void read(char &a) { cin >> a; }
inline void read(double &a) { cin >> a; }
inline void read(long double &a) { cin >> a; }
inline void read(string &a) { cin >> a; }
template<class T, class S>
void read(pair<T, S> &p) {
    read(p.first), read(p.second);
}
template<class T>
void read(vector<T> &a) {
    for (auto &i: a) read(i);
}
template<class T>
void read(T &a) {
    cin >> a;
}
#define debug(x) cout << #x << ' ' << x << endl;
const int maxn = 2e5 + 10;
const ll mod = 998244353;

void solve() {
	nin;
	vector<string> v(n); read(v);

	sort(all(v), [](auto&a, auto&b) {
		return a.size() < b.size();
	});

	auto d = *v.begin();
	vector<string> sub;
	for (int i = 0; i < d.size(); i++) {
		for (int j = i+1; j <= d.size(); j++) {
			sub.eb(d.substr(i, j-i));
		}
	}
	sort(all(sub), [](auto&a, auto&b) {
		return a.size() > b.size();
	});

	for (int i = 0; i < sub.size(); i++) {
		auto s = sub[i];
		auto rev = s;
		reverse_all(rev);

		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (v[j].find(s) == string::npos && v[j].find(rev) == string::npos) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << s.size() << endl;
			break;
		}
	}
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}