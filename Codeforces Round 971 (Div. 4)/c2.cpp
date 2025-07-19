#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;  
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        long long moves_x = (x + k - 1) / k;  // ceil(x/k)
        long long moves_y = (y + k - 1) / k;  // ceil(y/k)

        long long total_moves = max(moves_x, moves_y) * 2;

        if (x > y) {
            cout << total_moves-1 << endl;
        } else {
            cout << total_moves << endl;
        }

    }
    return 0;
}
