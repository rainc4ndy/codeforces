#include <iostream>
#include <cmath>
using namespace std;

bool can_reach(int x, int y, int k, int n) {
    long long moves_x = (n + 1) / 2;  // ceil(n / 2)
    long long moves_y = n / 2;        // floor(n / 2)
    
    long long max_x = moves_x * k;
    long long max_y = moves_y * k;
    
    return (x <= max_x && y <= max_y);
}

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        int left = 0, right = 2 * (max(x, y) / k + 1), ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (can_reach(x, y, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
