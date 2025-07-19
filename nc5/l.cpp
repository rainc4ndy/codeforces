#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[101];
void solve() {
	int n;
	cin >> n;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		tot += v[i];
	}

	int mid = tot/n;

	for (int i = n; i >= 1; i--) {
		if (v[i] <= mid)
			continue;
		for (int j = 1; j < n; j++) {
			if (v[j] < mid) {
				int r = mid - v[j];
				v[j] += r;
				v[i] -= r;
			}
		}
	}

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= v[i];
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