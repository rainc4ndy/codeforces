#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
int r;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> r;
    v.resize(r);

    // 输入金字塔数据
    for (int i = 0; i < r; i++) {
        v[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }

    // 使用动态规划自底向上更新每个节点的最大路径权重
    for (int i = r - 2; i >= 0; i--) { // 从倒数第二行开始向上
        for (int j = 0; j <= i; j++) { // 遍历当前行的每个节点
            // 更新当前节点的最大路径权重
            v[i][j] += max(v[i + 1][j], v[i + 1][j + 1]);
        }
    }

    // 最大路径权重存储在金字塔的顶部
    cout << v[0][0] << endl;
    return 0;
}
