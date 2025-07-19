#include <bits/stdc++.h>
using namespace std;

const int mod = 1e5 + 10;
typedef long long ll;

ll diff[mod];
ll arr[mod];
ll pa[mod];

void solve() {
    ll n, d, k;
    cin >> n >> d >> k;

    memset(diff, 0, sizeof(diff));
    memset(arr, 0, sizeof(arr));
    memset(pa, 0, sizeof(pa));

    int l, r;
    for (int i = 1; i <= k; i++) {
        cin >> l >> r;
        diff[l] += 1;      
        diff[r + 1] -= 1;   
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + diff[i];
    }

    ll a = LLONG_MIN, b = LLONG_MAX; 
    ll ai = -1, bi = -1;

    cout <<"arr:";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    } 
    cout <<endl;

    for (int i = 1; i + d - 1 <= n; i++) {
        // Find the maximum value in the current window
        ll current_max = LLONG_MIN;
        for (int j = i; j < i + d; j++) {
            current_max = max(current_max, arr[j]);
        }

        if (current_max > a) {
            a = current_max;
            ai = i;
        }

        if (current_max < b) {
            b = current_max;
            bi = i;
        }
    }

    cout << "----------" << endl;
    cout << ai << ' ' << bi << endl;
    cout << "----------" << endl;
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
