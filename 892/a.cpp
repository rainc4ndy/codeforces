#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	set<int> ss;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ss.insert(v[i]);
	}
	if (ss.size() == 1) {
		cout << -1 << endl;
		return;
	}
	int mi = 0x3f3f3f3f, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < mi) {
			mi = v[i];
			cnt = 1;
		} else if (v[i] == mi) {
			cnt++;
		}
	}
	cout << cnt << ' ' << n-cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << mi << ' ';
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		if (v[i] == mi) continue;

		cout << v[i] << ' ';
	}
	cout << endl;

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