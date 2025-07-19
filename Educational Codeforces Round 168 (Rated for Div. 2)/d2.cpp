#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<int> st;
    int cost = 0;
    int balance = 0;
    
    for (int i = 0; i < n; i++) {
        char ch = (i % 2 == 0) ? '_' : s[i];

        if (ch == '(') {
            st.push(i);
            balance++;
        } else if (ch == ')') {
            if (!st.empty()) {
                cost += i - st.top();
                st.pop();
            }
            balance--;
        } else { // ch == '_'
            if (balance > 0) {
                if (!st.empty()) {
                    cost += i - st.top();
                    st.pop();
                }
                balance--;
            } else {
                st.push(i);
                balance++;
            }
        }
    }

    cout << cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
