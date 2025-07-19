#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int k = sqrt(n); 

    if (k * k != n) {
        cout << "No" << endl;
        return;
    }

    bool isBeautiful = true;

    for (int i = 0; i < k; i++) {
        if (s[i] != '1' || s[n - k + i] != '1') {
            isBeautiful = false;
            break;
        }
    }

    for (int i = 1; i < k - 1; i++) {
        if (s[i * k] != '1' || s[(i + 1) * k - 1] != '1') {
            isBeautiful = false;
            break;
        }

        for (int j = 1; j < k - 1; j++) {
            if (s[i * k + j] != '0') {
                isBeautiful = false;
                break;
            }
        }

        if (!isBeautiful) break;
    }

    if (isBeautiful) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
