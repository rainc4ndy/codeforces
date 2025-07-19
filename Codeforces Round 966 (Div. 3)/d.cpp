#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;

int v[mod];
int pa[mod];

void solve() {
    int n;
    cin >> n;

    pa[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pa[i] = pa[i - 1] + v[i];
    }

    string s;
    cin >> s;

    vector<int> l, r;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') l.push_back(i + 1);
        if (s[i] == 'R') r.push_back(i + 1);
    }

    int cur = 0;
    reverse(r.begin(), r.end()); 

    vector<pair<int, ll>> op;
    int x = 0;

    for (int i = 0; i < l.size(); i++) {
        if (x >= r.size()) break;
        if (r[x] > l[i]) {
            int l_idx = l[i];
            int r_idx = r[x];
            op.push_back({r_idx - l_idx, pa[r_idx] - pa[l_idx - 1]});
            x++;
        }
    }

    sort(op.begin(), op.end()); // Sort by segment length

    for (auto it : op) {
    	if (it.second > 0)
        	cur += it.second;
    }

    cout << cur << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}