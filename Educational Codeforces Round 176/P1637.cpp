#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 3e4+10;
typedef long long ll;

class MyTree {
public:
    vector<int> v;
    int sz;
    MyTree(int sz) {
        this->sz = sz;
        v.resize(sz + 1);
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, int value) {
        while (x <= sz) {
            v[x] += value;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int sum = 0;
        while (x > 0) {
            sum += v[x];
            x -= lowbit(x);
        }
        return sum;
    }
};

MyTree f1(MAXN), f2(MAXN);

void solve() {
    int n;
    cin >> n;

    vector<ll> arr(n + 1);
    vector<ll> sorted_arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sorted_arr[i] = arr[i];  // 复制数组用于排序
    }

    sort(next(begin(sorted_arr)), end(sorted_arr)); // 仅排序副本
    auto f = [&](ll x) { 
        return lower_bound(next(begin(sorted_arr)), end(sorted_arr), x) - sorted_arr.begin(); 
    };

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int idx = f(arr[i]);
        f1.add(idx, 1);
        f2.add(idx, f1.query(idx - 1));  // 确保索引合法
        ans += f2.query(idx - 1);
    }
    cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    solve();
    return 0;
}
