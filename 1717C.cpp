#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000001], b[1000001];
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        bool flag = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        b[n + 1] = b[1];
        for (int i = 1; i <= n; i++) {
            if (a[i] > b[i] || (a[i] < b[i] && b[i] > b[i + 1] + 1)) {
                cout << "NO\n";
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
    }
    return 0;
}