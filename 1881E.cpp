#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MX = 1e5+10;

int main() {
    int n;
    cin >> n;
    vector<int> freq(MX, 0);  // 用于存储每个数字的频率

    // 输入数字并计算频率
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<long long> dp(MX, 0);  // 动态规划数组

    // 初始化
    dp[1] = freq[1];
    // 动态规划计算最大贡献
    for (int i = 2; i < MX; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + static_cast<long long>(i) * freq[i]);
    }

    // 输出结果
    cout << dp[MX] << endl;

    return 0;
}