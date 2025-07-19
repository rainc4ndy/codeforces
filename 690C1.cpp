#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

vector<int> e[MAXN];
int deg[MAXN] = {};
bool vis[MAXN] = {};
int n, m;

void kahn() {
    queue<int> q;
    
    // Initialize queue with all nodes of degree 1
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            q.push(i);
            vis[i] = true;
        }
    }

    int cnt = 0;  // Count of processed nodes
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        
        for (int neighbor : e[cur]) {
            if (vis[neighbor])
                continue;
            
            deg[neighbor]--;
            if (deg[neighbor] == 1) {
                q.push(neighbor);
                vis[neighbor] = true;
            }
        }
    }

    // Check if all nodes are processed
    if (cnt != n) {
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    
    kahn();
    
    return 0;
}
