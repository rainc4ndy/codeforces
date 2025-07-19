#include <iostream>
#include <cmath>

using namespace std;

int min_colors_needed(int n, int m, int k) {
    int blocks_rows = (n + k - 1) / k; // Equivalent to ceil(n / k)
    int blocks_cols = (m + k - 1) / k; // Equivalent to ceil(m / k)
    return (n - blocks_rows) * (m - blocks_cols) + (blocks_rows*blocks_cols);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << min_colors_needed(n, m, k) << "\n";
    }
    
    return 0;
}
