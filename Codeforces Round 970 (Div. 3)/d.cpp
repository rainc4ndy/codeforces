#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> color(n);
    vector<bool> visited(n, false);
    vector<int> result(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        color[i] = s[i] - '0';
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int current = i;
            
            while (!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                current = p[current];
            }
            
            int blackCount = 0;
            for (int node : cycle) {
                if (color[node] == 0) {
                    blackCount++;
                }
            }
            
            for (int node : cycle) {
                result[node] = blackCount;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
