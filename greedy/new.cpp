#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
    cout << "test" << endl;
    short n, v;
    n = 5, v = 10;
    // cin >> n >> v;
    
    vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0)); // Initialize dp with 0

    vector<P> d{
        {1, 2},  // item 1: weight 2, value 1
        {4, 6},  // item 2: weight 6, value 4
        {5, 10}, // item 3: weight 10, value 5
        {4, 8},  // item 4: weight 8, value 4
        {2, 4}   // item 5: weight 4, value 2
    };
    
    // Dynamic programming to solve the 0/1 Knapsack problem
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) { // Check capacity from 0 to v
            // If current item can be included
            if (j - d[i - 1].x >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - d[i - 1].x] + d[i - 1].y);
            } else {
                dp[i][j] = dp[i - 1][j]; // If we can't include the current item
            }
        }
    }

    // Print the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) { 
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    // The result will be the maximum value achievable with n items and capacity v
    cout << dp[n][v] << endl;
}

int main() {    
    int _ = 1;
    while (_--) solve();
    return 0;
}
