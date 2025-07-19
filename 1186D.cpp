#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> a(n);
    vector<int> b(n);
    vector<int> can_round_up;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = floor(a[i]);
        sum += b[i];
        if (fabs(a[i] - b[i]) > 1e-8) {
            can_round_up.push_back(i);
        }
    }

    int i = 0;
    while (sum < 0 && i < (int)can_round_up.size()) {
        int idx = can_round_up[i++];
        b[idx] += 1;
        sum += 1;
    }

    for (int x : b)
        cout << x << '\n';

    return 0;
}
