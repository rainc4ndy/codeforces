#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int vertical = m + accumulate(begin(y), end(y), 0) - y[0],
        horizon =  m + accumulate(begin(x), end(x), 0) - x[0];
    cout << 2 * (vertical + horizon) << endl;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        solve(); // Process each test case
    }
    return 0;
}
