#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate the middle point
        long long mid = (2 * k + n - 1) / 2;

        // Compute the minimum possible value of x
        long long min_x = abs(mid - (k + n - 1));


        

        cout << min_x << endl;
    }

    return 0;
}
