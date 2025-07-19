#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define fastio ios::sync_with_stdio(0), cin.tie(0)

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    int mx = n + 5;
    vi suffix_mex(n);
    set<int> mex_set;
    for (int i = 0; i < mx; ++i) mex_set.insert(i);

    vector<int> cnt(mx, 0);
    for (int i = n - 1; i >= 0; --i) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1) mex_set.erase(a[i]);
        suffix_mex[i] = *mex_set.begin();
    }

    // 重置
    fill(cnt.begin(), cnt.end(), 0);
    mex_set.clear();
    for (int i = 0; i < mx; ++i) mex_set.insert(i);

    vi ans;
    int l = 0;
    while (l < n) {
        int current_mex = suffix_mex[l];
        int r = l;
        int unique = 0;

        // 局部频率表
        vi local_cnt(mx, 0);

        // 扫到这一段包含所有 [0, current_mex-1] 的数
        while (r < n) {
            int val = a[r];
            cnt[val]++;
            local_cnt[val]++;
            if (cnt[val] == 1) mex_set.erase(val);

            if (val < current_mex && local_cnt[val] == 1) {
                unique++;
            }

            if (unique == current_mex) break;
            r++;
        }

        ans.eb(current_mex);

        for (int i = l; i <= r; ++i) {
            int val = a[i];
            cnt[val]--;
            if (cnt[val] == 0) mex_set.insert(val);
        }
        l = r + 1;
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
