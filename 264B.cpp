#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> dp(MAXN, 1); // dp[i] 表示以 v[i] 结尾的最长好序列长度
unordered_map<int, int> factor_dp; // 记录因子对应的最长好序列长度

void solve() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        int x = v[i];
        vector<int> factors; 
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                factors.push_back(j);
                while (x % j == 0) x /= j; // 去掉所有 j 因子
            }
        }
        if (x > 1) factors.push_back(x); // x 本身是质数

        // 使用所有因子的最大 dp 值
        for (int f : factors) {
            dp[i] = max(dp[i], factor_dp[f] + 1);
        }

        // 更新因子哈希表中的最长序列
        for (int f : factors) {
            factor_dp[f] = max(factor_dp[f], dp[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.begin() + n + 1) << "\n";
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int _ = 1;
    while (_--) solve();

    return 0;
}
