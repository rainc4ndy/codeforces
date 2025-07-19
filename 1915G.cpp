#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <queue>
#include <random>
#include <vector>
using namespace std;

typedef long long ll;
using pll = pair<ll, ll>;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)

// 分层图最短路：状态为 (city, 当前 slowness)
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    const int MAXS = 1000;
    const ll INF = LLONG_MAX / 4;
    vector<vector<ll>> dis(n + 1, vector<ll>(MAXS + 1, INF));
    vector<vector<bool>> vis(n + 1, vector<bool>(MAXS + 1, false));

    using Node = array<ll, 3>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dis[1][s[1]] = 0;
    pq.push({0, s[1], 1});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        ll d = cur[0];
        int cur_s = cur[1];
        int u = cur[2];
        if (vis[u][cur_s]) continue;
        vis[u][cur_s] = true;
        // 1) 可以在当前城市再买一辆车，换成更慢的 s[u]（也就是原来逻辑中的更好的车）
        if (cur_s > s[u] && d < dis[u][s[u]]) {
            dis[u][s[u]] = d;
            pq.push({d, s[u], u});
        }
        // 2) 保持当前车速 cur_s，用它去相邻城市
        for (auto &e : graph[u]) {
            int v = e.first;
            int w = e.second;
            ll nd = d + (ll)cur_s * w;
            if (nd < dis[v][cur_s]) {
                dis[v][cur_s] = nd;
                pq.push({nd, cur_s, v});
            }
        }
    }

    ll ans = INF;
    for (int k = 1; k <= MAXS; ++k) {
        ans = min(ans, dis[n][k]);
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
