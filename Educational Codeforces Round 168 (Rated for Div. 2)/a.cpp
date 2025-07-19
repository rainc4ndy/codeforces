#include <bits/stdc++.h> 
using namespace std;

int f(const string &s) {
    if (s.empty()) return 0;
    int time = 2; 
    for (size_t i = 1; i < s.size(); ++i) {
        time += (s[i] == s[i - 1]) ? 1 : 2;
    }
    return time;
}

void solve() {
    string s;
    cin >> s;

    int maxTime = 0;
    string ans = s;

    for (char c = 'a'; c <= 'z'; ++c) {
        for (size_t i = 0; i <= s.size(); ++i) {
            string newString = s.substr(0, i) + c + s.substr(i);
            int newTime = f(newString);
            if (newTime > maxTime) {
                maxTime = newTime;
                ans = newString;
            }
        }
    }

    cout << ans << endl;
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
