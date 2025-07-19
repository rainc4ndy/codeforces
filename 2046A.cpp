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
        vector<ll> v1(n), v2(n);
        for (int i = 0; i < n; i++) cin >> v1[i];
        for (int i = 0; i < n; i++) cin >> v2[i];

        ll sumMax = 0, bestMin = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            sumMax += max(v1[i], v2[i]);
            bestMin = max(bestMin, min(v1[i], v2[i]));
        }
        cout << sumMax + bestMin << "\n";
    }
    return 0;
}
