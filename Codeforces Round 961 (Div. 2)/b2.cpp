#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod];
ll cnt[mod];
ll cnt_ori[mod];
void solve() {
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cnt[i];
        cnt_ori[i] = cnt[i];
    }

    sort(v, v + n);

    int l = 0, r = 0;
    ll sum = 0;
    ll max_petals = 0;

    while (r < n) {
        sum += v[r];
        

        // Check if the current subarray is valid
        while (v[r] - v[l] > 1) {
            sum -= v[l];
            l++;
        }

        if (sum <= m) {
            max_petals = max(max_petals, sum);
        } else {
            while (sum > m && l <= r) {
                sum -= v[l];
                l++;
            }
            max_petals = max(max_petals, sum);
        }

        cnt[r]--;
        if (!cnt[r])
            r++;
    }

    cout << max_petals << endl;
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
