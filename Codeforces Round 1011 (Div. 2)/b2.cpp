#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<pii> operations; 
    
    while (a.size() > 1) {
        int mex_val = 0;
        unordered_set<int> s(a.begin(), a.end());

        while (s.count(mex_val)) mex_val++;

        bool found = false;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                unordered_set<int> sub_set(a.begin() + i, a.begin() + j + 1);
                int local_mex = 0;
                while (sub_set.count(local_mex)) local_mex++;

                if (local_mex == mex_val) {
                    operations.emplace_back(i + 1, j + 1);
                    a.erase(a.begin() + i, a.begin() + j + 1);
                    a.insert(a.begin() + i, mex_val);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }

    cout << operations.size() << '\n';
    for (auto &[l, r] : operations) {
        cout << l << " " << r << '\n';
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
