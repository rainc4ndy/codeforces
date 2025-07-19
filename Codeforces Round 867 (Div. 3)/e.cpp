#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;
#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"
#define debug(x) cout << #x << ' ' << x << endl;
#define debug1(x)                     \
    RED;                              \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug2(x)                     \
    GREEN;                            \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug3(x)                     \
    BLUE;                             \
    cout << #x << ' ' << x << endl; \
    RESET;
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (n & 1) {
        cout << -1 << "\n";
        return;
    }

    int half = n/2;
    string s1 = s.substr(0, half), s2 = s.substr(half);
    reverse(s2.begin(), s2.end());

    // 1) collect bad pairs
    vector<vector<int>> bad_by_char(26);
    vector<bool> is_bad(half, false);
    for (int i = 0; i < half; i++) {
        if (s1[i] == s2[i]) {
            int c = s1[i] - 'a';
            bad_by_char[c].push_back(i);
            is_bad[i] = true;
        }
    }
    // precompute counts
    vector<int> cnt(26);
    int B = 0;
    for (int c = 0; c < 26; c++) {
        cnt[c] = bad_by_char[c].size();
        B += cnt[c];
    }

    int ans = 0;

    for (int i = 0; i < half; i++) {
        if (!is_bad[i]) continue;
        char c0 = s1[i];                  
        int i0 = c0 - 'a';
        int best_c = -1, best_cnt = -1;
        for (int c = 0; c < 26; c++) {
            if (c == i0) continue;
            if (cnt[c] > best_cnt) {
                best_cnt = cnt[c];
                best_c = c;
            }
        }
        if (best_c >= 0 && best_cnt > 0) {
            int j = bad_by_char[best_c].back();
            bad_by_char[best_c].pop_back();
            cnt[best_c]--;
            is_bad[j] = false;  

            swap(s1[i], s1[j]);
            ans++;
        }
        else {
            bool done = false;
            for (int j = 0; j < half && !done; j++) {
                if (!is_bad[j] && s2[j] != c0) {
                    swap(s2[j], s1[i]);
                    ans++;
                    done = true;
                }
                else if (!is_bad[j] && s1[j] != c0) {
                    swap(s1[j], s1[i]);
                    ans++;
                    done = true;
                }
            }
            if (!done) {
                cout << -1 << "\n";
                return;
            }
        }
        is_bad[i] = false; 
    }

    cout << ans << "\n";
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}
