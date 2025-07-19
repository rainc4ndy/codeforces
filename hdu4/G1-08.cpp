#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX_N = 3001;

int numSpies, briberyCount, numEdges;

vector<vector<int>> adj(MAX_N);
vector<int> briberyCost(MAX_N, INF);
vector<bool> visited(MAX_N, false);
int reachableCount = 0;

void dfs(int u) {
    if (visited[u])
        return;
    visited[u] = true;
    reachableCount++;
    for (int v : adj[u])
        dfs(v);
}


vector<int> disc(MAX_N, 0), low(MAX_N, 0); // Discovery and low-link values
vector<bool> inStack(MAX_N, false);         // Indicates if a node is in the stack
vector<int> st;                             // Stack to hold nodes in the current DFS branch
vector<int> comp(MAX_N, 0);                   // Representative of the SCC to which node belongs
vector<int> compMin(MAX_N, INF);              // Minimum bribery cost within the SCC


int timeCounter = 0; // Global time counter for DFS order

// Tarjan's algorithm to find strongly connected components (SCCs)
void tarjan(int u) {
    disc[u] = low[u] = ++timeCounter;
    st.push_back(u);
    inStack[u] = true;
    
    for (int v : adj[u]) {
        if (disc[v] == 0) { 
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    
    if (disc[u] == low[u]) {
        // Use u as the representative for this SCC.
        compMin[u] = INF;
        while (true) {
            int w = st.back();
            st.pop_back();
            inStack[w] = false;
            comp[w] = u;
            compMin[u] = min(compMin[u], briberyCost[w]);
            if (w == u)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> numSpies >> briberyCount;
    for (int i = 1; i <= numSpies; i++) {
        briberyCost[i] = INF;
    }
    for (int i = 1; i <= briberyCount; i++) {
        int spy, cost;
        cin >> spy >> cost;
        briberyCost[spy] = cost;
    }
    
    cin >> numEdges;
    for (int i = 1; i <= numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // 检查连通性
    for (int i = 1; i <= numSpies; i++) {
        if (briberyCost[i] != INF)
            dfs(i);
    }
    if (reachableCount < numSpies) {
        cout << "NO\n";
        for (int i = 1; i <= numSpies; i++) {
            if (!visited[i]) {
                cout << i;
                return 0;
            }
        }
    }
    
    // *************************************************
    timeCounter = 0;
    for (int i = 1; i <= numSpies; i++) {
        disc[i] = 0;
        inStack[i] = false;
    }
    
    // 在可以贿赂的间谍节点进行tarjan
    for (int i = 1; i <= numSpies; i++) {
        if (briberyCost[i] != INF && disc[i] == 0)
            tarjan(i);
    }
    
    // Build the condensed graph and compute the in-degree of each component.
    // 入度
    vector<int> indegree(MAX_N, 0);
    for (int u = 1; u <= numSpies; u++) {
        for (int v : adj[u]) {
            if (comp[u] != comp[v]) {
                indegree[ comp[v] ]++;
            }
        }
    }
    
    int totalCost = 0;
    for (int i = 1; i <= numSpies; i++) {
        // A component is represented by i if comp[i] == i.
        if (comp[i] == i && indegree[i] == 0)
            totalCost += compMin[i];
    }
    
    cout << "YES\n" << totalCost;
    return 0;
}
