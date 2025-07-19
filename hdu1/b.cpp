#include <bits/stdc++.h> 
#include <cmath>
#include <random>
#include <utility>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

bool check(ll x) {
	ll sum = (x * (x + 1)) / 2;
	ll k = std::sqrt(sum);
	return k * k == sum;
}


void solve() {
	ll n;
	cin >> n; 
	if (check(n)) {
		cout << -1 << endl;
		return;
	}

	vector<ll> ans(n);
	std::iota(ans.begin(), ans.end(), 1);

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ans[i];
		ll k = std::sqrt(sum);
		if (k * k == sum) {
			sum -= ans[i];
			swap(ans[i], ans[i+1]);
			sum += ans[i];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
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