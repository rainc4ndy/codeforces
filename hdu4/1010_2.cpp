#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        // 预处理客户数据，计算 U = x+y 和 V = x-y 的最值
        long long Umin = LLONG_MAX, Umax = LLONG_MIN;
        long long Vmin = LLONG_MAX, Vmax = LLONG_MIN;
        for (int i = 0; i < n; i++){
            long long x, y;
            cin >> x >> y;
            long long U = x + y;
            long long V = x - y;
            Umin = min(Umin, U);
            Umax = max(Umax, U);
            Vmin = min(Vmin, V);
            Vmax = max(Vmax, V);
        }
        long long ans = LLONG_MAX;
        // 遍历每个候选配送站，计算到所有客户的最大曼哈顿距离
        for (int j = 0; j < m; j++){
            long long a, b;
            cin >> a >> b;
            long long U0 = a + b;
            long long V0 = a - b;
            // 四个方向的距离
            long long d1 = Umax - U0;
            long long d2 = U0 - Umin;
            long long d3 = Vmax - V0;
            long long d4 = V0 - Vmin;
            long long d = max(max(d1, d2), max(d3, d4));
            ans = min(ans, d);
        }
        cout << ans << "\n";
    }
    return 0;
}
