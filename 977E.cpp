#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> g[maxn];
bool vis[maxn];

int nodes, edges;
bool valid;

void dfs(int u) {
    vis[u] = true;
    nodes++;
    if (g[u].size() != 2) valid = false;
    for (int v : g[u]) {
        edges++;
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    // 清空图
    for (int i = 0; i < n; i++) {
        g[i].clear();
        vis[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            nodes = 0;
            edges = 0;
            valid = true;
            dfs(i);
            edges /= 2; // 无向边每条算了两次
            if (valid && nodes >= 3 && edges == nodes) {
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
