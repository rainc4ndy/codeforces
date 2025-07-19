#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

char v[mod] {};

int n;
void solve() {
	cin >> n;

	for (int i = 1; i <= n;i++) cin >> v[i];

	int ans = 0;
	v[0] = ')';
	v[n+1] = '(';

	for (int i = 1; i <= n; i++) {
		if (v[i] == '_') {
			if (v[i+1] == ')' && v[i-1] == ')') {
				ans++;
			} 
			else if (v[i+1] == '(' && v[i-1] == '(') {
				ans++;
			}
			else if (v[i+1] == ')' && v[i-1] == '(') {
				ans += 4;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}