#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
};

vector<int> dijkstra(int n, const vector<vector<Edge>>& graph, int start) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_vertex]) {
            continue;
        }

        for (const Edge& edge : graph[current_vertex]) {
            int new_dist = current_dist + edge.weight;
            if (new_dist < dist[edge.to]) {
                dist[edge.to] = new_dist;
                pq.push({new_dist, edge.to});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;

        vector<vector<Edge>> graph(n + 1);
        vector<int> horses(h);

        for (int i = 0; i < h; i++) {
            cin >> horses[i];
        }

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> marian_dist = dijkstra(n, graph, 1);
        vector<int> robin_dist = dijkstra(n, graph, n);

        vector<int> horse_dist_marian = marian_dist;
        vector<int> horse_dist_robin = robin_dist;

        for (int horse : horses) {
            for (const Edge& edge : graph[horse]) {
                horse_dist_marian[edge.to] = min(horse_dist_marian[edge.to], marian_dist[horse] + edge.weight / 2);
                horse_dist_robin[edge.to] = min(horse_dist_robin[edge.to], robin_dist[horse] + edge.weight / 2);
            }
        }

        int earliest_meeting_time = INF;
        for (int v = 1; v <= n; v++) {
            earliest_meeting_time = min(earliest_meeting_time, min(horse_dist_marian[v], horse_dist_robin[v]));
        }

        cout << (earliest_meeting_time != INF ? earliest_meeting_time : -1) << '\n';
    }

    return 0;
}
