#include <bits/stdc++.h> 
#include <complex>
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
	string s;
	cin >> s;

	vector<P> v;
	bool f = false;
	int a, b;
	int cnt =0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			cnt++;
		}
		if (!f) {
			if (s[i] == '1' && i+1 != n && s[i+1] == '0') {
				f = true;
				a = i;
			}
		} else {
			if (s[i] == '0' && i+1 != n && s[i+1] == '1') {
				f = false;
				b = i+1;
				v.emplace_back(a, b);
			}
		}
	}

	if ( v.size() == 0) {
		if (cnt == 0) {
			if (n > 2 && !(n & 1)) {
				cout << "YES" << endl;
				return;
			}
		} 
		cout << "NO" << endl;
		return;
	}

	set<int> d;
	for (int i = 0; i < v.size()-1; i++) {
		d.insert(v[i].x - v[i+1].x);
		d.insert(v[i].y - v[i+1].y);
	}

	if (d.size() > 1) {
		cout << "NO" << endl;
	} else {
		int le = v[0].x;
		int re = n - v[v.size()-1].y-1;

		if (le == re && le == v[0].y - v[0].x + 1) {
			int col = v.size() + 2;
			if (le == col) {
				cout << "YES" << endl;
			}else cout << "NO" << endl;
		}  else cout << "NO" << endl;
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