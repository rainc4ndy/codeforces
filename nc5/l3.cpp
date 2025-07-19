#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[101];
void solve() {
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        tot += v[i];
    }

    // 计算均分情况
    int q = tot / n; // 每个元素理想值的下界
    int r = tot % n; // 需要增加的次数

    // 计算最大乘积
    ll ans = 1;
    // r 个元素为 q+1，其余 (n-r) 个元素为 q
    for (int i = 0; i < r; i++) {
        ans *= (q + 1);
    }
    for (int i = r; i < n; i++) {
        ans *= q;
    }

    cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
