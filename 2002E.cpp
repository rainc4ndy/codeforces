#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using ll = long long;
using pll = pair<ll, ll>;

void solve() {
    int n;
    cin >> n;
    vector<pll> stk; // {amount, color}

    for (int i = 0; i < n; ++i) {
        ll amt, color;
        cin >> amt >> color;
        color++; // for 1-based
        while (!stk.empty() && stk.back().first <= amt) {
            if (stk.size() >= 2 && stk[stk.size() - 2].second == color) {
                amt += stk[stk.size() - 2].first - stk.back().first;
                stk.pop_back();
                stk.pop_back();
            } else {
                stk.pop_back();
            }
        }

        stk.emplace_back(amt, color);
        cout << stk.front().first << ' ';
    }

    cout << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}