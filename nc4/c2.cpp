#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int operations = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int cycle_length = 0;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = v[current];
                cycle_length++;
            }
            operations += (cycle_length + 3) / 4;  // Equivalent to ceil(cycle_length / 4.0)
        }
    }

    cout << operations << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
