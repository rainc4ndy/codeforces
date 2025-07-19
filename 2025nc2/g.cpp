#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;

    if (m == 1) {
        cout << 1 << endl;
        return;
    }

    ll temp = m;  // 初始温度
    ll p = 1;     // 计数次数
    ll bestDiff = abs(temp - n);
    ll ans = 1;

    while (temp <= n) {
        ll nextTemp = temp * m;

        if (nextTemp < temp) break;  // 防止溢出

        ll diff = abs(nextTemp - n);
        if (diff < bestDiff) {
            bestDiff = diff;
            ans = p + 1;
        }

        temp = nextTemp;
        p++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
