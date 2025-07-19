#include <bits/stdc++.h> 
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,k;
	cin >> n >> k;

	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(begin(v), end(v));
	vector<ll> v2;
	int cnt = 0, pre = v[0];
	for (int i = 0; i < n; i++) {
		if (v[i] != pre) {
			v2.emplace_back(cnt);
			cnt = 1;
		} else {
			cnt++;
		}
		pre = v[i];
	}
	if (cnt) {
		v2.emplace_back(cnt);
	}

	ll ans = v2.size();
	sort(begin(v2), end(v2));
	for (int i = 0; i < v2.size(); i++) {
		if (k >= v2[i]) {
			k -= v2[i];
			ans--;
		} else {
			break;
		}
	}
	cout << max(1LL,ans) << endl;
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