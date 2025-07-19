#include <bits/stdc++.h>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

#define mod (501)
#define ll long long

ll v[mod][mod] {};
unordered_map<ll, int> um;
unordered_map<ll, int> ori;
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int t;
	cin >> t;
	ll n, a, c, d, mi;
	bool flag = true;
	vector<bool> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> n >> c >> d;

		mi = 0x3f3f3f3f;
		um.clear();
		ori.clear();
		vector<ll> tmp;

		flag = true;

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> v[j][k];
				mi = min(v[j][k], mi);
				ori[v[j][k]]++;
			}
		}

		for (int k = 0; k < n; ++k) {
	        for (int j = 0; j < n; ++j) {
	            int value = mi + k*c + j*d;
	            um[value]++;
	        }
	    }

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (um[v[j][k]] != ori[v[j][k]]) {
					flag = false;
					break; 
				}
			}
			if (!flag)
				break;
		}

		ans[i] = flag;
	}

	for (int i = 0; i < t; i++) {
		if (ans[i])
			cout << "YES";
		else
			cout << "NO";
		if (i != t - 1)
			cout << endl;
	}


	return 0;
}