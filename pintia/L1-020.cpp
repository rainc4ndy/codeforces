#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, tmp;
    bool t[100000] {};

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> k;
        for(int j = 0; j < k; ++j) {
            cin >> tmp;
            if (k == 1)
                break;
            t[tmp] = true;
        }
    }

    set<int> exist;
    vector<int> ans;

    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> tmp;
        if (!t[tmp] && !exist.count(tmp)) {
            ans.push_back(tmp);
            exist.insert(tmp);
        }
    }

    if (ans.empty()) {
        cout << "No one is handsome";
        return 0;
    }

    for (int i = 0; i < ans.size(); i++)  {
        cout << setfill('0') << setw(5) << ans[i];
        if (i != ans.size() - 1)
            cout << ' ';
    }

    return 0;
}
