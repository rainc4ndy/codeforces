#include <iostream>
#include <string>

using namespace std;

bool f(const string& s) {
    int i = 0;
    while (i < s.size()) {
        if (i + 5 <= s.size() && s.substr(i, 5) == "avava") {
            i += 5;
        } else if (i + 3 <= s.size() && s.substr(i, 3) == "ava") {
            i += 3;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (f(s)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
