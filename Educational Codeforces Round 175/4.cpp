#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

constexpr int maxn = 10000;
int adj[maxn], used[maxn];
class Solution {
public:
    int maxWeight(vector<vector<int>>& edges, vector<int>& value) {
        int n = value.size();
        int m = edges.size();
        vector<pair<int, int>> edge;
        for(auto& v : edges) edge.push_back({v[0], v[1]});
        vector<vector<int>> G(n);
        sort(edge.begin(), edge.end(), [&](const pair<int, int>& p, const pair<int, int>& q){
            return value[p.first] + value[p.second] > value[q.first] + value[q.second];
        });
        for(auto& [u, v] : edge){
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = 0;
        for(int i = 0; i < n; i += 1){
            for(int& v : G[i]) adj[v] = 1;
            vector<int> ve;
            for(int k = 0; k < m; k += 1) if(adj[edge[k].first] and adj[edge[k].second]) ve.push_back(k);
            for(int j = 0; j < min(3, (int)ve.size()); j += 1){
                used[edge[ve[j]].first] = used[edge[ve[j]].second] = 1;
                int bans = value[i] + value[edge[ve[j]].first] + value[edge[ve[j]].second];
                for(int& k :ve){
                    int pans = bans;
                    if(not used[edge[k].first]) pans += value[edge[k].first];
                    if(not used[edge[k].second]) pans += value[edge[k].second];
                    if(pans > ans) ans = pans;
                }
                used[edge[ve[j]].first] = used[edge[ve[j]].second] = 0;
            }
            for(int& v : G[i]) adj[v] = 0;
        }
        return ans;
    }
};




void solve() {
    //code
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int _;
    cin >> _;
    while(_--) solve();

    return 0;
}