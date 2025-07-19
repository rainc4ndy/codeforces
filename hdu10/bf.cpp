#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &x : v) cin >> x;

        int ans = 0;
        // 枚举所有 i < j 的组合
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (__gcd(v[i], v[j]) == abs(v[i] - v[j])) {
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
