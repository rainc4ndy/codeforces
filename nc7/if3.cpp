#include <iostream>
using namespace std;

typedef long long ll;

ll m, k, h;

bool canDefeatMonster(ll initialMachines) {
    if (k == m) {
        return initialMachines >= h;
    }
    
    long long machines = initialMachines;
    long long totalMachines = initialMachines;
    
    while (machines >= m) {
        long long newMachines = (machines / m) * k;
        totalMachines += newMachines;
        machines = machines % m + newMachines;
        if (totalMachines >= h) return true;
    }
    
    return totalMachines >= h;
}


void solve() {
    cin >> m >> k >> h;

    if (k >= m) {
        cout << min(m, h) << endl;
        return;
    }

    ll l = m, r = h;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (canDefeatMonster(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
