#include <algorithm>
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
	int n;
	cin >> n; 
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(begin(v), end(v));
	auto check = [&](int x) {
		for (int i = 0; i < n; i++) {
			if (x >= v[i]) {
				if (i >= n/2) {
					return false;
				}
			} else {
				break;
			}
		}
		return true;
	};

	int ans = 1, l = 0, r = 1e9, mid;
	while (l <= r) {
		mid = (l+r)>>1;
		if (check(mid)) {
			l = mid+1;
			ans = mid;
		} else {
			r = mid-1;
		}
	}
	cout << ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}