#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

vector<int> e[mod];
int w[mod];
bool visited[mod];

int remain = 0;

int get_cnt(int root) {
    visited[root] = true;
    int maxDepth = 0;
    
    for (int neighbor : e[root]) {
        if (!visited[neighbor]) {
            maxDepth = max(maxDepth, get_cnt(neighbor));
        }
    }
    
    return maxDepth + 1;
}

int mx = 0;
int dfs(int root, bool inPath, int currentCount) {
    visited[root] = true;
    int maxCount = (inPath ? currentCount : 0);

    bool ok = false;
    for (int neighbor : e[root]) {
        if (!visited[neighbor]) {
            if (w[neighbor] == 1) {
                ok = true;
                maxCount = max(maxCount, dfs(neighbor, true, currentCount + 1));
                mx = max(mx, maxCount);
            }
        }
    }
    if (!ok && mx == currentCount) {
        remain = get_cnt(root);
    }
    return maxCount;
}

void solve() {
    int n;
    cin >> n;

    // Clear 
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        visited[i] = false;
    }
    memset(w, 0, sizeof(w));
    mx = 0;

    int x, y, k;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y >> k;

        e[x].push_back(y);
        e[y].push_back(x);
        w[y] = k;
    }

    visited[1] = true;
    int ones = dfs(1, w[1] == 1, w[1] == 1 ? 1 : 0);
    
    cout << "ONES " << ones << endl;
    cout << "remain " << remain << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
