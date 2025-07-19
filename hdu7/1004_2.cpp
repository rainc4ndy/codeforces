#include <bits/stdc++.h>
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
	string s; cin >> s;

	// 方案: 找出所有0, 1的连续区间
	// 对于每个查询和op，我们需要找到一个 最早的 区间[l,r] 且 r-l+1 <= k
	// 这需要一种能支持随机访问，且在插入和删除时保持有序的数据结构
	// 随机访问用于二分搜索一个最早的区间  r-l+1 <= k   O(logn)
	// 插入和删除用于修改0和1的区间信息， O(logn)
	for(int l = 0; l < (int)s.size(); ){
        int r = l;
        while(r+1 < (int)s.size() && s[r+1] == s[l]) ++r;
        int len = r - l + 1;
        if(s[l] == '0') {

        }
        else  {

        }
        l = r + 1;
    }

    int q; cin >> q;
    while(q--){
    	int op, k;
        cin >> op >> k;
        if(op == 0){

        } else {

        }
    }

}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}