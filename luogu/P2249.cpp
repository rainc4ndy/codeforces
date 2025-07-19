#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;

	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<ll> ans(m);

	ll x;
	for (int i = 0; i < m; i++) {
		cin >> x;

		ans[i] = lower_bound(v.begin(), v.end(), x) - v.begin();
		if (v[ans[i]] != x)
			ans[i] = -1;
		else 
			ans[i]++;
	}

	for (int i =0 ; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size()-1)
			cout << ' ';
	}

	return 0;
}