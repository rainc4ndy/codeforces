#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, k, g;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    //检查 最小的连续递增序列
    if (k * (k + 1) / 2 > n) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i * i <= n; i++) {
        if (n % i) //n因子
            continue;

        if (k * (k + 1) / 2 <= i) {
            g = max(g, n / i);
        }
        if (k * (k + 1) / 2 <= n / i) {
            g = max(g, (ll)i);
        }
    }
    n /= g;
    for (int i = 1; i < k; i++) {
        cout << i*g << " ";
        n -= i;
    }
    cout << n*g;
    return 0;
}