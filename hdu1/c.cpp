#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
    int n, st, en;
    cin >> n >> st >> en;

    vector<vector<int>> graph(n+1);
    vector<bool> vis(n+1, false);

    function<void(int)> dfs_1 = [&](int pa) {
        for (auto it : graph[pa]) {
            if (vis[it])
                continue;
            vis[it] = true;
            dfs_1(it);
            vis[it] = false;
        }
        cout << pa << ' ';
    };

    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    vis[en] = true;
    dfs_1(en);
    vis[en] = false;
    cout << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int _;
    cin >> _;
    while (_--) solve();

    return 0;
}
