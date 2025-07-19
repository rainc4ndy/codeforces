#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> h1(n), h2(n);
    for (int i = 0; i < n; ++i) cin >> h1[i];
    for (int i = 0; i < n; ++i) cin >> h2[i];

    // DP 数组
    vector<int> dp1(n), dp2(n);
    dp1[0] = h1[0];
    dp2[0] = h2[0];

    for (int i = 1; i < n; ++i) {
        dp1[i] = max(dp1[i - 1], dp2[i - 1] + h1[i]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + h2[i]);
    }

    cout << max(dp1[n - 1], dp2[n - 1]) << endl;
    return 0;
}
