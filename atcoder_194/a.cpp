#include <bits/stdc++.h> 
#include <numeric>
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

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}


	vector<ll> d;
	d.push_back(v[0]);
	ll sum = v[0];
	for (int i = 1; i < n; i++) {
		ll b = d.back();
		if (b <= 0) {
			if (v[i] <= 0) {
				d.pop_back();
				cout << "p0" << endl;
			} else if (v[i] + b > 0) {
				d.push_back(v[i]);
				cout << "p" << endl;
			}
		} else {
			if (v[i] < 0) {
				if (abs(v[i]) < b) {
					d.push_back(v[i]);
					cout << "p" << endl;
				} else {
					d.pop_back();
					cout << "p0" << endl;
				}
			}
		}
	}
	cout << std::accumulate(d.begin(), d.end(), 0);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}