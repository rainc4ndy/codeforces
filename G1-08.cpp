#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7; 
typedef long long ll;
typedef pair<int, int> P;
#define int ll

void solve() {
    int n, p;
    cin >> n >> p;

    vector<int> cost(n + 1, INF);
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        cost[x] = y;
    }

    int r;
    cin >> r;
    for (int i = 0; i < r; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

	int ans = 0;
    vector<int> low(n + 1), dfn(n + 1);
    int ts = 0;
    stack<int> stk;
    vector<bool> in_stk(n + 1);
    
    function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++ts;
        stk.push(u);
        in_stk[u] = true;

        for (int v : graph[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (dfn[u] == low[u]) {
        	int mi = INF;
            while (true) {
                int v = stk.top();
                stk.pop();
                in_stk[v] = false;
                mi = min(mi, cost[v]);
                if (v == u) break;
            }
            ans += mi;
        }
    };
    // 遍历所有点，确保所有的 SCC 都被找到
    for (int i = 1; i <= n; i++) {
        if (!dfn[i] && cost[i] != INF) {  // 未被访问的节点，而且可以被贿赂
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            cout << "NO" << endl << i; 
            return;
        }
    }

    cout << "YES" << endl << ans;
}

signed main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) solve();

    return 0;
}
