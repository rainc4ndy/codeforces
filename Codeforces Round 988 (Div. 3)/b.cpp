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
	map<int, int> ss;
	for (int i =0 ;i < n; i++) {
		cin >> v[i];
		ss[v[i]]++;
	}

	ll cnt = n-2;
	for (int i = 0; i < n; i++) {
		if (cnt % v[i] == 0 && ss[cnt / v[i]]) {
			if (cnt / v[i] == v[i]) {
				if (ss[cnt / v[i]] <= 1)
					continue;
			}
			cout << v[i] << ' ' << cnt / v[i] << endl;
			return;
		}
	}

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