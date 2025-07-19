#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int M = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            M = max(M, a[i]);
        }
        vector<ll> cnt(M+1, 0);
        for (int x : a) cnt[x]++;

        ll ans = 0;
        for (int d = 1; d <= M; d++) {
            for (int kd = d; kd + d <= M; kd += d) {
                ans += cnt[kd] * cnt[kd + d];
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
