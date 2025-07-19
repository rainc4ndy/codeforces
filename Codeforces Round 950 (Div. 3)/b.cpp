#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    int fav_value = v[f - 1];
    
    sort(v.rbegin(), v.rend());
    
    int count_fav = count(v.begin(), v.end(), fav_value);
    int position_fav_start = find(v.begin(), v.end(), fav_value) - v.begin();
    int position_fav_end = position_fav_start + count_fav - 1;

    if (position_fav_start < k) {
        if (position_fav_end < k) {
            cout << "YES" << endl;
        } else {
            cout << "MAYBE" << endl;
        }
    } else {
        cout << "NO" << endl;
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
