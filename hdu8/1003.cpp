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

const int INF = 1e9;
int T, N, M;
bool blocked[505][505];
int dist[505][505];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void solve() {
    cin >> N >> M;
    mem(blocked, 0);
    for (int i = 1; i <= N; ++i) {
        int r, x;
        cin >> r;
        for (int j = 0; j < r; ++j) {
            cin >> x;
            blocked[i][x] = true;
        }
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= N; ++i) {
        if (!blocked[i][1]) {
            dist[i][1] = 1;
            q.push({i, 1});
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !blocked[nx][ny] && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= N; ++i) {
        ans = min(ans, dist[i][M]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        for (int i = 0; i < 505; ++i)
            fill(dist[i], dist[i] + 505, INF);
        solve();
    }
    return 0;
}
