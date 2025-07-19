#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int x, y;
string a, b;
void solve() {
    int n, m;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;

    int max_k = 0;
    int j = 0;

    // Iterate through the string 'a'
    for (int i = 0; i < n; ++i) {
        // Find the current character of 'a' in 'b'
        while (j < m && b[j] != a[i]) {
            ++j;
        }
        // If we found the character in 'b'
        if (j < m) {
            max_k = i + 1;
            ++j;  // Move to the next character in 'b'
        } else {
            break;  // We cannot find this character in 'b', stop searching
        }
    }

    cout << max_k << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}