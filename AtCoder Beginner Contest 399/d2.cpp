#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> A(2 * n);
    // 记录每个数字的两次出现位置，使用1-based索引
    unordered_map<int, pii> pos;
    for (int i = 0; i < 2 * n; i++) {
        cin >> A[i];
        if (pos[A[i]].first == 0)
            pos[A[i]].first = i + 1;
        else
            pos[A[i]].second = i + 1;
    }
    
    // 离散化所有出现的位置
    vector<int> endpoints;
    for (auto &[num, p] : pos) {
        endpoints.push_back(p.first);
        endpoints.push_back(p.second);
    }
    sort(endpoints.begin(), endpoints.end());
    unordered_map<int, int> compressed;
    for (int i = 0; i < (int)endpoints.size(); i++) {
        compressed[endpoints[i]] = i + 1;
    }
    
    // 构造前缀和数组：记录每个离散化位置上端点的个数
    vector<int> prefix(2 * n + 1, 0);
    for (auto &[num, p] : pos) {
        prefix[compressed[p.first]]++;
        prefix[compressed[p.second]]++;
    }
    for (int i = 1; i <= 2 * n; i++) {
        prefix[i] += prefix[i - 1];
    }
    
    // 枚举所有数字对 (a,b)
    int count = 0;
    for (auto &[a, p1] : pos) {
        for (auto &[b, p2] : pos) {
            if (a >= b) continue; // 保证每对只计算一次
            
            // 离散化后的坐标
            int x1 = compressed[p1.first], x2 = compressed[p1.second];
            int y1 = compressed[p2.first], y2 = compressed[p2.second];
            
            // 如果某个情侣本来就相邻，跳过
            if (abs(x1 - x2) == 1 || abs(y1 - y2) == 1) continue;
            
            // 假设我们希望将这两对情侣合并，
            // 检查两对情侣之间是否有其他端点干扰
            // 即在区间 [min(x2, y2) + 1, max(x1, y1) - 1] 内是否没有其他端点
            if (prefix[max(x1, y1)] - prefix[min(x2, y2)] == 0) {
                count++;
            }
        }
    }
    
    cout << count << "\n";
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
