#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        int S = a + 2 * b;

        // Check if the total sum is even
        if (S % 2 != 0) {
            cout << "NO" << endl;
        } else {
            int target = S / 2;

            // Check if we can form the target sum using twos and ones
            if (target <= 2 * b && target % 2 <= a) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
