#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll k = n / 2;
        ll R = (k * (k + 1)) % MOD;
        cout << R << endl;
    }
    return 0;
}
