#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 5;
const double pi = acos(-1);
int n, k, x, y;
double a[N];
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		a[i] = atan2(y, x);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)a[i + n] = a[i] + 2 * pi;
	double ans = 0;
	for (int i = 1; i <= n; ++i)ans = max(ans, a[i + k] - a[i]);
	cout << fixed << setprecision(12) << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--)solve();
}
