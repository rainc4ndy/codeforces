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

using ll = long long;

void solve() {
    ll n, u, k, hq;
    cin >> n >> u >> k >> hq;

	using E = tuple<ll, ll, ll>; // {剩余生命, 攻击力, 编号}

    priority_queue<E, vector<E>, greater<E>> pq;
    unordered_map<ll, ll> dmg;  // 攻击的次数
    multiset<ll> attack;

    for (ll i = 0; i < n; i++) {
        ll a, h;
        cin >> a >> h;
        pq.emplace(h, a, i);
        attack.insert(a);
    }

    ll ans = 0;
    while (hq > 0 && !pq.empty()) {
        auto [hp, atk, id] = pq.top();
        pq.pop();
        if (dmg[id] >= k) continue; 
        ll damage = (dmg[id] == 0) ? u : u / 2;
        hp -= damage;
        dmg[id]++;

        bool killed = (hp <= 0);
        if (killed) {
            auto it = attack.find(atk);
            if(it != attack.end())
                attack.erase(it);
            ans++;
        } else {
            pq.emplace(hp, atk, id);
        }

        if (!attack.empty()) {
            hq -= *attack.rbegin(); 
            if (hq <= 0) break;
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
