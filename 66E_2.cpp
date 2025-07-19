#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> solveClockwise(const vector<ll>& gas, const vector<ll>& cost) {
    int n = gas.size();
    vector<ll> g(2*n), d(2*n);
    for (int i = 0; i < n; i++) {
        g[i] = gas[i]; d[i] = cost[i];
        g[i+n] = gas[i]; d[i+n] = cost[i];
    }
    // 计算前缀和 dp，dp[0]=0, dp[i+1]=dp[i]+g[i]-d[i]
    vector<ll> dp(2*n+1, 0);
    for (int i = 0; i < 2*n; i++) {
        dp[i+1] = dp[i] + (g[i] - d[i]);
    }
    // 维护区间最小值的线段树
    struct SegTree {
        int n;
        vector<ll> mn;
        SegTree(int _n): n(_n), mn(4*_n, LLONG_MAX) {}
        void build(int p, int l, int r, const vector<ll>& a) {
            if (l+1 == r) { mn[p] = a[l]; return; }
            int m = (l + r) >> 1;
            build(p<<1, l, m, a);
            build(p<<1|1, m, r, a);
            mn[p] = min(mn[p<<1], mn[p<<1|1]);
        }
        ll queryMin(int p, int l, int r, int L, int R) {
            if (r <= L || R <= l) return LLONG_MAX;
            if (L <= l && r <= R) return mn[p];
            int m = (l + r) >> 1;
            return min(queryMin(p<<1, l, m, L, R),
                       queryMin(p<<1|1, m, r, L, R));
        }
    } st(2*n+1);
    st.build(1, 0, 2*n+1, dp);

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ll mn = st.queryMin(1, 0, 2*n+1, i+1, i+n+1);
        if (mn - dp[i] >= 0) ans.push_back(i+1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> ans_cw = solveClockwise(a, b);
    vector<ll> ar(n), br(n);
    for (int i = 0; i < n; i++) {
        ar[i] = a[(n - i) % n];
        br[i] = b[(n - i) % n];
    }
    vector<int> ans_rev = solveClockwise(ar, br);
    vector<int> ans_ccw;
    for (int idx : ans_rev) {
        int j = (n - (idx-1) % n) % n;  // 原始 0-based 站点
        ans_ccw.push_back(j+1);
    }

    vector<bool> ok(n, false);
    for (int x : ans_cw) ok[x-1] = true;
    for (int x : ans_ccw) ok[x-1] = true;
    vector<int> final_ans;
    for (int i = 0; i < n; i++) if (ok[i]) final_ans.push_back(i+1);

    cout << final_ans.size() << "\n";
    for (int x : final_ans) cout << x << " ";
    cout << "\n";
    return 0;
}
