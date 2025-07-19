#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int type; // 0 or 1
};

vector<vector<Edge>> graph;
vector<int> bestPath;
vector<int> currentPath;

void dfs(int node, int parent) {
    vector<int> path;
    int maxLength = 0;

    // Visit all neighbors
    for (const Edge& edge : graph[node]) {
        if (edge.to == parent) continue;

        // Perform DFS
        dfs(edge.to, node);

        // Update the best path found
        if (currentPath.size() > maxLength) {
            maxLength = currentPath.size();
            bestPath = currentPath;
        }
        currentPath.clear();
    }

    // Add the current edge to the path
    path.push_back(0); // Dummy value for now
    if (!parent) path.pop_back(); // If it's root, remove dummy value
    
    // Append edges based on their type
    for (const Edge& edge : graph[node]) {
        if (edge.to != parent) {
            path.push_back(edge.type);
        }
    }

    if (path.size() > bestPath.size()) {
        bestPath = path;
    }
}

int main() {
    int n;
    cin >> n;
    graph.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    dfs(1, -1);

    cout << "Constructed path: ";
    for (int val : bestPath) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
