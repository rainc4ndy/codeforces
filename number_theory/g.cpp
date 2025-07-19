#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int power(int a, int b) {
    int res = 1;
    while(b) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n), freq(1001, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
        }

        // cnt[d]：数组中是 d 的倍数的数的个数
        vector<int> cnt(1001, 0);
        for (int d = 1; d <= 1000; ++d)
            for (int mult = d; mult <= 1000; mult += d)
                cnt[d] += freq[mult];

        // f[d]：GCD 恰好为 d 的子集个数
        vector<int> f(1001, 0);

        for (int d = 1000; d >= 1; --d) {
            if (cnt[d] == 0) continue;
            int total = power(2, cnt[d]) - 1; // 所有元素都是 d 的倍数的子集数量
            for (int mult = 2 * d; mult <= 1000; mult += d)
                total = (total - f[mult] + MOD) % MOD;
            f[d] = total;
        }

        int ans = 0;
        for (int d = 1; d <= 1000; ++d)
            ans = (ans + 1LL * d * f[d]) % MOD;

        cout << ans << '\n';
    }

    return 0;
}
