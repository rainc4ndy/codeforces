#include <bits/stdc++.h>
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
const int maxn = 3e6 + 10;
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

// 如果为0，则没有顶点。否则就是目前顶点编号
int nex[maxn][2], cnt = 0;
int rec[maxn]; //这个节点被多少个用过

void insert(int x) {
	int cur = 0;
	for (int i = 31; i >= 0; i--) {
		int b = (x >> i) & 1;
		if (nex[cur][b] == 0) {
			nex[cur][b] = ++cnt;
		}
		cur = nex[cur][b];
		rec[cur]++;
	}
}
void del(int x) {
	int cur = 0;
	for (int i = 31; i >= 0; i--) {
		int b = (x >> i) & 1;
		if (!nex[cur][b])
			return;
		cur = nex[cur][b];
		rec[cur]--;
	}
}

int query(int x) {
	int ans = 0;
	int cur = 0;
	for (int i = 31; i >= 0; i--) {
		// 能否走相反的边
		int b = (x >> i) & 1;
		ll desire = b ^ 1;
		if (nex[cur][desire] && rec[nex[cur][desire]]) {
			ans |= (1ULL << i);
			cur = nex[cur][desire];
		} else {
			ans &= ~(1ULL << i);
			cur = nex[cur][b];
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	insert(0);
	for (int i =0;i < n;i++) {
		char c;
		int x;
		cin >> c >> x;
		if (c == '+') {
			insert(x);
		} else if (c == '-') {
			del(x);
		} else {
			cout << query(x) << endl;
		}
	}
} 

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}