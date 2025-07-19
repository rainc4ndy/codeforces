#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int i, n, m, temp = 0, ans = 1;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> m;
            temp = gcd(ans, m);
            ans = ans / temp * m;
        }
        cout << ans << '\n';
    }
    return 0;
}