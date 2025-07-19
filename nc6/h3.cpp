#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int sz = s.size();
    
    int l = 0, r = 0;
    char cnt[256] = {};  
    while (r < sz) {
        cnt[s[r]]++;
        if (r - l + 1 == 10) {
            if (cnt['4'] == 0 && cnt['5'] == 0 && cnt['U'] == 0) {
                cout << "invalid" << endl;
                return;
            }
            cnt[s[l]]--;
            l++;
        }
        r++;
    }
    
    l = 0; r = 0;
    memset(cnt, 0, sizeof(cnt)); 
    while (r < sz) {
        cnt[s[r]]++;
        if (r - l + 1 == 90) { 
            if (cnt['5'] == 0 && cnt['U'] == 0) {
                cout << "invalid" << endl;
                return;
            }
            cnt[s[l]]--;
            l++;
        }
        r++;
    }

    bool ok = false;
    int left = -1;
    for (int i = 0; i < sz; i++) {
        if (s[i] == 'U') {
            if (left != -1) ok = true;
        }
        if (s[i] == '5') {
            if (left == -1) {
                left = i; 
            } else {
                if (!ok) { 
                    cout << "invalid" << endl;
                    return;
                }
                ok = false; 
                left = i; 
            }
        }
    }
    
    cout << "valid" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
