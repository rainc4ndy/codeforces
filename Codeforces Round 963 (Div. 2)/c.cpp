#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
        }

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(a[i]);
        }

        int on_count = 0;
        ll time = 0;
        while (on_count < n) {
            ll next_toggle = pq.top();
            pq.pop();

            if (next_toggle > time) {
                time = next_toggle;
            }

            on_count++;
            if (on_count == n) {
                break;
            }

            pq.push(next_toggle + k);
        }

        if (on_count == n) {
            cout << time << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}