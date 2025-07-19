#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6 + 10;
typedef long long ll;
typedef pair<int, int> P;

vector<int> e[mod];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int ans = 0;
    int r = 1;
    for (int l = 1; l <= n; l++) {
        while (r <= n) {
            bool allFriends = true;
            for (int i = l; i < r; i++) {
                if (find(e[i].begin(), e[i].end(), r) == e[i].end()) {
                    allFriends = false;
                    break;
                }
            }
            if (!allFriends) break;
            r++;
        }
        ans += (r - l);
    }

    cout << ans << '\n';

    return 0;
}
