#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Info {
    ll mi, sum;
    Info() : mi(LLONG_MAX), sum(0) {}
    Info(ll x) : mi(x), sum(x) {}
    Info(ll _mi, ll _sum) : mi(_mi), sum(_sum) {}
    friend Info operator+(const Info &a, const Info &b) {
        return Info(min(a.mi, b.mi), a.sum + b.sum);
    }
};

struct SegmentTree {
    int n;
    vector<ll> tag;
    vector<Info> info;
    SegmentTree(int _n) : n(_n), tag(4*n, 0), info(4*n) {}

    void pull(int p) {
        info[p] = info[p<<1] + info[p<<1|1];
    }

    void apply(int p, int len, ll v) {
        tag[p] += v;
        info[p].mi += v;
        info[p].sum += v * len;
    }

    void push(int p, int l, int r) {
        if (tag[p] != 0) {
            int m = (l + r) >> 1;
            apply(p<<1, m-l, tag[p]);
            apply(p<<1|1, r-m, tag[p]);
            tag[p] = 0;
        }
    }

    void modify(int p, int l, int r, int idx, ll v) {
        if (l + 1 == r) {
            info[p] = Info(v);
            return;
        }
        push(p, l, r);
        int m = (l + r) >> 1;
        if (idx < m) modify(p<<1, l, m, idx, v);
        else          modify(p<<1|1, m, r, idx, v);
        pull(p);
    }
    void modify(int idx, ll v) {
        modify(1, 0, n, idx, v);
    }

    void rangeAdd(int p, int l, int r, int L, int R, ll v) {
        if (r <= L || R <= l) return;
        if (L <= l && r <= R) {
            apply(p, r-l, v);
            return;
        }
        push(p, l, r);
        int m = (l + r) >> 1;
        rangeAdd(p<<1, l, m, L, R, v);
        rangeAdd(p<<1|1, m, r, L, R, v);
        pull(p);
    }
    void rangeAdd(int L, int R, ll v) {
        rangeAdd(1, 0, n, L, R, v);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (r <= L || R <= l) return Info(0);
        if (L <= l && r <= R) return info[p];
        push(p, l, r);
        int m = (l + r) >> 1;
        return query(p<<1, l, m, L, R) + query(p<<1|1, m, r, L, R);
    }
    ll queryMin(int L, int R) {
        return query(1, 0, n, L, R).mi;
    }
    ll querySum(int L, int R) {
        return query(1, 0, n, L, R).sum;
    }
};

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> g(n), d(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    // extend to 2n for circular handling
    g.resize(2*n);
    d.resize(2*n);
    for (int i = 0; i < n; i++) {
        g[n+i] = g[i];
        d[n+i] = d[i];
    }

    // compute prefix dp
    vector<ll> dp(2*n);
    dp[0] = g[0] - d[0];
    for (int i = 1; i < 2*n; i++) {
        dp[i] = dp[i-1] + g[i] - d[i];
    }

    // build segment tree over dp
    SegmentTree sg(2*n);
    for (int i = 0; i < 2*n; i++) {
        sg.modify(i, dp[i]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ll base = dp[i];
        // shift range so dp[i] becomes 0
        sg.rangeAdd(i, 2*n, -base);
        // check minimum in [i+1, i+n]
        if (sg.queryMin(i+1, i+n+1) >= 0) {
            ans.push_back(i+1);
        }
        // restore
        sg.rangeAdd(i, 2*n, base);
    }

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
