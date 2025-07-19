#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
    ull x;
    cin >> x;
//1000000000000000000
    if (x == 1) {
        cout << "-1" << endl;
        return;
    }

    if ((x & (x - 1)) == 0) {
        cout << "-1" << endl;
    } else {
        if (x % 2 != 0) {
            cout << x - 1 << endl;
        } else {
            for (ull i = x-2; i >= 2; i -= 2) {
				if (__gcd(i, x) == (i ^ x)) {
					cout << i << endl;
					return;
				}
			}
			cout << "-1" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
