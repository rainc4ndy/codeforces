#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;

    while (t--) {
        ll n, k, q;
        cin >> n >> k >> q;

        vector<ll> a(k+1), b(k+1);
        a[0] = 0;
        b[0] = 0;

        for (int j = 1; j <= k; j++) {
            cin >> a[j];
        }
        for (int j = 1; j <= k; j++) {
            cin >> b[j];
        }

        for (int j = 0; j < q; j++) {
            ll p;
            cin >> p;

            if (p == 0) {
                cout << "0 ";
                continue;
            }

            auto it = lower_bound(a.begin(), a.end(), p);
            int idx = it - a.begin();

            if (*it > p) idx--; 

            double speed = (double)(b[idx + 1] - b[idx]) / (a[idx + 1] - a[idx]);
            ll result = b[idx] + ((p - a[idx]) * speed);
            
            cout << result << " ";
        }
        cout << "\n";
    }

    return 0;
}
