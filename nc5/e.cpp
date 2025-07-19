#include <bits/stdc++.h> 
#include <cmath>
using namespace std;

const int mod = 1e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll a[mod], b[mod];

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	int ans = 0;
	map<ll, ll> cnt;
	for (int i = 1; i <= n; i++) {
		if (a[i] > b[i])
			ans++;
		else if (a[i] == b[i]) {
			cnt[a[i]]++;
		}
	}
	for (auto it : cnt) {
		ans += (it.y+1)/2;
	}
	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t; 
	cin >> t;
	while(t--)
		solve();

	return 0;
}