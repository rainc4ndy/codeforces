#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> indices(m);
    vector<char> chars(m);

    for (int i = 0; i < m; ++i) {
        cin >> indices[i];
        indices[i]--;  // Convert to zero-based index
    }

    for (int i = 0; i < m; ++i) {
        cin >> chars[i];
    }

    // Sort indices and characters
    sort(indices.begin(), indices.end());
    sort(chars.begin(), chars.end());

    // Priority queue to manage the characters we have not used yet
    priority_queue<char, vector<char>, greater<char>> pq(chars.begin(), chars.end());

    vector<bool> vis(n, false);

    for (int i = 0; i < m; ++i) {
        int pos = indices[i];
        char ch = pq.top();
        pq.pop();

        // If the position is not visited yet, or the current char is smaller than existing
        if (!vis[pos] || ch < s[pos]) {
            s[pos] = ch;
            vis[pos] = true;
        } else {
            // Push the character back if it cannot be used
            pq.push(ch);
        }
    }

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
