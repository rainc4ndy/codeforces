#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long count = 0;

    // Iterate over all possible starting points of subsegments
    for (int start = 0; start < n; start++) {
        int current_sum = 0;

        // Iterate over all possible ending points of subsegments
        for (int end = start; end < n; end++) {
            current_sum += a[end];

            // If at any point the sum exceeds x, break out of the loop
            if (current_sum > x) {
                break;
            }

            // If the sum never exceeds x, it is a valid subsegment
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
