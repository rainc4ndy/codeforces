#include <bits/stdc++.h>
#include <functional>
#include <queue>
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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	using Node = array<int, 3>; // {cost, player, pos}
	const int INF = 1e9;

	vector<vector<int>> dis(n, vector<int>(2, INF));
	vector<vector<bool>> vis(n, vector<bool>(2, false));
	priority_queue<Node, vector<Node>, greater<>> pq;

	dis[0][0] = v[0]; // 如果是 hard，需要一个 skip point
	pq.push({dis[0][0], 0, 0});
	if (n > 1) {
		dis[1][0] = v[0] + v[1];
		pq.push({dis[1][0], 0, 1});
	}

	while (!pq.empty()) {
		auto [cost, player, pos] = pq.top(); pq.pop();
		if (vis[pos][player]) continue;
		vis[pos][player] = true;

		// 下一轮是另外一个玩家
		int next_player = 1 - player;

		// 打一个 boss
		if (pos + 1 < n) {
			int new_cost = cost + (next_player == 0 ? v[pos + 1] : 0);
			if (new_cost < dis[pos + 1][next_player]) {
				dis[pos + 1][next_player] = new_cost;
				pq.push({new_cost, next_player, pos + 1});
			}
		}

		// 打两个 boss
		if (pos + 2 < n) {
			int add = (next_player == 0 ? v[pos + 1] + v[pos + 2] : 0);
			int new_cost = cost + add;
			if (new_cost < dis[pos + 2][next_player]) {
				dis[pos + 2][next_player] = new_cost;
				pq.push({new_cost, next_player, pos + 2});
			}
		}
	}

	cout << min(dis[n - 1][0], dis[n - 1][1]) << '\n';
}
int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}