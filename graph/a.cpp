#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vb = vector<bool>;
#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof(arr))
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0)
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
#define nin                                                                    \
  ll n;                                                                        \
  cin >> n
//.........Bit_Manipulation...........//
#define msb(mask) (63 - __builtin_clzll(mask))
#define lsb(mask) __builtin_ctzll(mask)
#define cntsetbit(mask) __builtin_popcount(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))
#define setbit(mask, bit) ((mask) | (1LL << (bit)))
#define resetbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define togglebit(mask, bit) ((mask) ^ (1LL << bit))
//.........Fast Input...........//
inline void read(int &a) { cin >> a; }
inline void read(ll &a) { cin >> a; }
inline void read(char &a) { cin >> a; }
inline void read(double &a) { cin >> a; }
inline void read(long double &a) { cin >> a; }
inline void read(string &a) { cin >> a; }
template <class T, class S> void read(pair<T, S> &p) {
	read(p.first), read(p.second);
}
template <class T> void read(vector<T> &a) {
	for (auto &i : a)
		read(i);
}
template <class T> void read(T &a) { cin >> a; }
#define TIME cout << (double)clock() / CLOCKS_PER_SEC << "ms" << endl;
#define debug(x) cout << #x << ' ' << x << endl;
const int maxn = 2e5 + 10;
const ll mod = 998244353;

constexpr int MAXN = 250;
constexpr int INF = 0x3f3f3f3f;

struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct EK {
	int n, m;            // n：点数，m：边数
	vector<Edge> edges;  // edges：所有边的集合
	vector<int> G[MAXN]; // G：点 x -> x 的所有边在 edges 中的下标
	int a[MAXN], p[MAXN]; // a：点 x -> BFS 过程中最近接近点 x 的边给它的最大流
	// p：点 x -> BFS 过程中最近接近点 x 的边
	void init(int n) {
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int cap) {
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	int Maxflow(int s, int t) {
		int flow = 0;
		for (;;) {
			memset(a, 0, sizeof(a));
			queue<int> Q;
			Q.push(s);
			a[s] = INF;
			while (!Q.empty()) {
				int x = Q.front();
				Q.pop();
				for (int i = 0; i < G[x].size(); i++) { // 遍历以 x 作为起点的边
					Edge &e = edges[G[x][i]];
					if (!a[e.to] && e.cap > e.flow) {
						p[e.to] = G[x][i]; // G[x][i] 是最近接近点 e.to 的边
						a[e.to] =
						    min(a[x], e.cap - e.flow); // 最近接近点 e.to 的边赋给它的流
						Q.push(e.to);
					}
				}
				if (a[t])
					break; // 如果汇点接受到了流，就退出 BFS
			}
			if (!a[t])
				break; // 如果汇点没有接受到流，说明源点和汇点不在同一个连通分量上
			for (int u = t; u != s;
			        u = edges[p[u]].from) { // 通过 u 追寻 BFS 过程中 s -> t 的路径
				edges[p[u]].flow += a[t];     // 增加路径上边的 flow 值
				edges[p[u] ^ 1].flow -= a[t]; // 减小反向路径的 flow 值
			}
			flow += a[t];
		}
		return flow;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	EK ek;
	ek.init(n+1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		ek.AddEdge(x, y, z);
	}
	cout << ek.Maxflow(1, n) << endl;
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--)
		solve();

	return 0;
}