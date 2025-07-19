#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    queue<pair<int, int>> q; 
    unordered_set<int> vis; 
    
    q.emplace(n, 0);
    vis.insert(n);

    while (!q.empty()) {
        auto [cur, step] = q.front();
        q.pop();

        if (cur == m) {
            cout << step << "\n"; 
            return;
        }

        if (cur < m && !vis.count(cur * 2)) {  
            q.emplace(cur * 2, step + 1);
            vis.insert(cur * 2);
        }

        if (cur > 1 && !vis.count(cur - 1)) {  
            q.emplace(cur - 1, step + 1);
            vis.insert(cur - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
