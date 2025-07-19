#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;

        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }

        unordered_map<char, int> charToNum;
        unordered_map<int, char> numToChar;
        bool valid = true;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            int num = a[i];

            if (charToNum.count(c)) {
                if (charToNum[c] != num) {
                    valid = false;
                    break;
                }
            } else {
                charToNum[c] = num;
            }

            if (numToChar.count(num)) {
                if (numToChar[num] != c) {
                    valid = false;
                    break;
                }
            } else {
                numToChar[num] = c;
            }
        }

        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
