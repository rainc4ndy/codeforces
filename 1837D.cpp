#include <bits/stdc++.h> 
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5+10;
const ll mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	int a = 0,b = 0;
	for (int i = 0; i <n; i++) {
		cin >> v[i];
		if (v[i] == '(') a++;
		else b++;
	}
	if (a != b) {
		cout << -1 << endl;
		return;
	}

	stack<int> stk;
	vector<int> col(n);
	set<int> s;

	for (int i = 0; i < n; i++) {
		if (v[i] == '(') {
			if (!stk.empty()) {
				if (v[stk.top()] == ')') {
					col[stk.top()] = 2;
					col[i] = 2;
					s.insert(col[i]);
					stk.pop();
				} else {
					stk.push(i);
				}
			} else {
				stk.push(i);
			}
		} else {
			if (!stk.empty()) {
				if (v[stk.top()] == '(') {
					col[stk.top()] = 1;
					col[i] = 1;
					s.insert(col[i]);
					stk.pop();
				} else {
					stk.push(i);
				}
			} else {
				stk.push(i);
			}
		}
	}

	if (s.size() == 1) {
		cout << 1 << endl;
		for (int i =0; i <n;i++) cout << 1 << ' ';
		cout << endl;
	} else {
		cout << s.size() << endl;
		for (auto it : col) cout << it << ' ';
		cout << endl;
	}
}

int main() {    
    fastio;
	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}