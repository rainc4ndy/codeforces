#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<P> nodes;
    for (int i = 1; i <= n; i++) {
        nodes.emplace_back(v[i], i);  // (value, index)
    }

    sort(nodes.rbegin(), nodes.rend());  // 按值降序排序

    vector<bool> removed(n + 1, false);
    ll total_energy = 0;

    for (auto &[val, node] : nodes) {
        if (removed[node]) continue;
        for (int neighbor : graph[node]) {
            if (!removed[neighbor]) {
                total_energy += v[neighbor];
            }
        }
        removed[node] = true;
    }

    cout << total_energy << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
