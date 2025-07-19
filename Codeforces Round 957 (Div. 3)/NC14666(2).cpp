#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50010;

int H[MAXN];
long long cntLeft[MAXN];
long long cntRight[MAXN];

void solve(int caseNum) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> H[i];
        cntLeft[i] = cntRight[i] = 0;
    }

    // 计算每座山左侧可见哨兵数量
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && H[stk.top()] < H[i]) {
            cntRight[stk.top()]++;
            stk.pop();
        }
        if (!stk.empty()) cntLeft[i]++;
        stk.push(i);
    }

    // 清空栈
    while (!stk.empty()) stk.pop();

    // 计算每座山右侧可见哨兵数量
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && H[stk.top()] < H[i]) {
            cntLeft[stk.top()]++;
            stk.pop();
        }
        if (!stk.empty()) cntRight[i]++;
        stk.push(i);
    }

    long long maxReduction = 0;
    int bestPosition = -1;

    // 计算在每个位置放置屏障的防守力减少量
    for (int X = 0; X < n; X++) {
        long long reduction = cntLeft[X] + cntRight[X];
        if (reduction > maxReduction) {
            maxReduction = reduction / 2;
            bestPosition = X+1;
        }
    }

    cout << "Case #" << caseNum << ": " << bestPosition << " " << maxReduction << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}
