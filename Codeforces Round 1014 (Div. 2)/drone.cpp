#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
 
#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5+10;
const ll mod = 998244353;
const ll INF = 1e18;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll m, n;
    cin >> m >> n;
    vector<ll> D(m);
    vector<pll> P(n); // 每个停靠站 (x, capacity)
 
    for (int i = 0; i < m; i++)
        cin >> D[i];
    for (int i = 0; i < n; i++)
        cin >> P[i].first;
    for (int i = 0; i < n; i++)
        cin >> P[i].second;
 
    // 排序：无人机位置按升序，停靠站也按位置升序
    sort(D.begin(), D.end());
    sort(P.begin(), P.end());

    // 预处理无人机坐标前缀和，方便计算区间和
    // prefix[0] = 0, prefix[i] = sum_{t=0}^{i-1} D[t]
    vector<ll> prefix(m+1, 0);
    for (int i = 0; i < m; i++)
        prefix[i+1] = prefix[i] + D[i];
 
 	// 计算区间 [l, r)（l 到 r-1）的无人机飞到坐标 X 的总距离
	// D 已排序，prefix[i] = sum_{t=0}^{i-1} D[t]
	auto cost = [&](int l, int r, ll X) -> ll {
	    // 找到区间中第一个大于 X 的位置
	    int pos = upper_bound(D.begin() + l, D.begin() + r, X) - D.begin();
	    // 对于 [l, pos): D[t] <= X, 距离为 X - D[t]
	    ll leftCount = pos - l;
	    ll costLeft = X * leftCount - (prefix[pos] - prefix[l]);
	    // 对于 [pos, r): D[t] > X, 距离为 D[t] - X
	    ll rightCount = r - pos;
	    ll costRight = (prefix[r] - prefix[pos]) - X * rightCount;
	    return costLeft + costRight;
	};

    // dp[i] 表示前 i 个无人机 分配完毕的最小总飞行距离
    vector<ll> dp(m+1, INF);
    dp[0] = 0;

 
    // 对于每个停靠站进行状态转移
    // 每个停靠站可以一次覆盖最多 P[j].second 个无人机（连续）
    for (int j = 0; j < n; j++) {
        ll stationX = P[j].first;
        int cap = P[j].second;
        // newdp 用来存储经过当前站更新后的状态
        vector<ll> newdp = dp;
 
        // 对于已经分配了 i 个无人机的状态，考虑分配下一个区间 [i, k)
        for (int i = 0; i < m; i++) {
            if (dp[i] == INF) continue;
            // k 为分配后总共覆盖的无人机数，不超过当前站容量
            for (int k = i + 1; k <= m && k - i <= cap; k++) {
                ll curCost = cost(i, k, stationX);
                newdp[k] = min(newdp[k], dp[i] + curCost);
            }
        }
        dp = newdp;
    }
 
    // 如果 dp[m] 为 INF，说明无法完成分配（通常题目保证可行性）
    cout << dp[m] << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // 如有多组数据，可启用下面代码： cin >> t;
    while(t--) solve();
    return 0;
}
