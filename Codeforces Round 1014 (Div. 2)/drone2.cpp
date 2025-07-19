#include <bits/stdc++.h>
using namespace std;

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
    vector<pll> P(n); // 每个停靠站 (位置，容量)
    
    for (int i = 0; i < m; i++)
        cin >> D[i];
    for (int j = 0; j < n; j++)
        cin >> P[j].first;
    for (int j = 0; j < n; j++)
        cin >> P[j].second;
    
    sort(D.begin(), D.end());
    sort(P.begin(), P.end());
    
    // dp[i] 表示前 i 个无人机分配完毕的最小总飞行距离
    vector<ll> dp(m+1, INF);
    dp[0] = 0;
    
    // 对于每个停靠站更新 dp 状态
    for (int j = 0; j < n; j++) {
        ll stationX = P[j].first;
        int cap = P[j].second;
        
        // 如果当前站点容量为 0，则无法分配无人机，此站不做转移
        if(cap == 0) continue;
        
        // 构造 Q 数组：Q[0]=0, Q[i] = sum_{t=0}^{i-1} |D[t] - stationX|
        vector<ll> Q(m+1, 0);
        for (int i = 1; i <= m; i++) {
            Q[i] = Q[i-1] + abs(D[i-1] - stationX);
        }
        
        vector<ll> newdp = dp;
        // 单调队列
        // 维护区间 [k-cap, k-1] 内的 dp[i]-Q[i] 的最小值
        deque<int> dq;
        
        // 初始化：候选 i=0
        dq.push_back(0);
        
        // 枚举 k 从 1 到 m
        for (int k = 1; k <= m; k++) {
            // 窗口左边界为 L = max(0, k-cap)
            int L = max(0, k - cap);
            // 移除窗口中不再满足 i >= L 的候选
            while (!dq.empty() && dq.front() < L) {
                dq.pop_front();
            }

            // dq.front() 即为区间 [L, k-1] 中 dp[i]-Q[i] 的最小值
            if (!dq.empty()) {
                newdp[k] = min(newdp[k], Q[k] + (dp[dq.front()] - Q[dq.front()]));
            }

            // 接下来准备将 k 加入候选集合
            // 计算 f(k) = dp[k]-Q[k]
            ll f_k = dp[k] - Q[k];
            // 移除队尾所有 f(i) >= f(k)
            while (!dq.empty() && (dp[dq.back()] - Q[dq.back()]) >= f_k) {
                dq.pop_back();
            }
            dq.push_back(k);
        }
        dp = newdp;
    }
    cout << dp[m] << endl;
}

int main(){
    fastio;

    int t = 1;
    while(t--) solve();
    return 0;
}
