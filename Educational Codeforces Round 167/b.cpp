#include <bits/stdc++.h> 
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    vector<int> ca(512, 0), cb(512, 0);
	for (int i = 0; i < a.size(); i++) {
		ca[a[i]]++;
	}	
	for (int i = 0; i < b.size(); i++) {
		cb[b[i]]++;
	}	


    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

	int ans = a.size() ;
	for (int i = 0; i < b.size(); i++) {
		if (ca[b[i]] > cb[b[i]])
			ans += abs(cb[b[i]] - ca[b[i]]);
	}
    ans -= dp[n][m];

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
