#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using ll = long long;

class MyTree {
public:
    vector<ll> v;
    ll sz;
    
    MyTree(ll sz) {
        this->sz = sz;
        v.resize(sz + 1);
    }

    ll lowbit(ll x) {
        return x & (-x);
    }

    void add(ll x, ll value) {
        while (x <= sz) {
            v[x] += value;
            x += lowbit(x);
        }
    }

    ll query(ll x) {
        ll sum = 0;
        while (x > 0) {
            sum += v[x];
            x -= lowbit(x);
        }
        return sum;
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> v(n + 1);
    MyTree fenwick(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        fenwick.add(i, v[i]);
    }

    vector<ll> ans;
    for (int i = 0; i < q; i++) {
        ll o, x, y;
        cin >> o >> x >> y;
        if (o == 1) {
            fenwick.add(x, y - (fenwick.query(x) - fenwick.query(x - 1)));
        } else {
            ll s = fenwick.query(y) / 100 - fenwick.query(x - 1) / 100;
            ans.push_back(s);
        }
    }

    ll dd = 0;
    for (int i = 0; i < ans.size(); i++) {
        dd ^= ans[i] * (i + 1);
    }

    cout << dd << endl;
}

int main() {    
    fastio;
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}
