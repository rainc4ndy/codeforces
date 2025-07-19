#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> paths(M, vector<int>(3));
    for (int i = 0; i < M; i++) {
        cin >> paths[i][0] >> paths[i][1] >> paths[i][2];
    }

    int cnt, start, end;
    cin >> cnt >> start >> end;

    vector<int> charge(N);
    for (int i = 0; i < N; i++) {
        cin >> charge[i];
    }

    // 初始化
    vector<vector<int>> dist(N, vector<int>(cnt + 1, INF));
    dist[start][0] = 0;

    // 建图邻接表
    vector<vector<pair<int, int>>> adj(N);
    for (auto &path : paths) {
        int u = path[0], v = path[1], w = path[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // 最小堆存储 {时间, 城市, 剩余电量}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, start, 0);

    int ans = -1;
    while (!pq.empty()) {
        auto [t, u, c] = pq.top();
        pq.pop();

        if (t > dist[u][c]) continue;
        if (u == end) {
            ans = t;
            break;
        }

        // 充电
        if (c < cnt) {
            int nt = t + charge[u];
            if (nt < dist[u][c + 1]) {
                dist[u][c + 1] = nt;
                pq.emplace(nt, u, c + 1);
            }
        }

        // 移动
        for (auto [v, w] : adj[u]) {
            if (c >= w) {
                int nt = t + w;
                if (nt < dist[v][c - w]) {
                    dist[v][c - w] = nt;
                    pq.emplace(nt, v, c - w);
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
