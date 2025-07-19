#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod] {};
void solve() {
	int n;
	
	cin >> n;

	bool b1 = false, b2 = false;
	for (int i = 0; i <n;i++) {
		cin >> v[i];
		if (v[i]&1) b1 = true;
		else b2 = true;
	} 

	if ((b1 && !b2) || (!b1 && b2)) {
		cout << 0 << endl;
		return;
	}

	sort(v,v+n);

	ll ans = 0;
	ll ji = 0, ou = 0;
	ll mx_ji = -1e9;
	ll sum = 0;
	for (int i = 0; i <n;i++) {
		if (v[i]&1) {
			if (ou > 0) {
				ans += ou;
				mx_ji = max(mx_ji, v[i]+sum);
				ou = 0;
				sum = 0;
			}
			ji++;
		} else {
			if (ji > 0) {
				if (mx_ji > v[i]) {
					ans++;
					mx_ji += v[i];
				} else {
					ans += 2;
					mx_ji = max(mx_ji, v[i]+mx_ji);
				}
			}
			sum += v[i];
			ou++;
		}
	}
	cout << "ans=" << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}