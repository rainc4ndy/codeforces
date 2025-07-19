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

	int a = 0, b = 0; // - _
	vector<char> v(n);
	for (int i =0; i < n;i++) {
		cin >> v[i];
		if (v[i] == '-') a++;
		else b++; 
	}

	int c = a, d =b;

	if (b < a) {
		//-_-_--------------
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (flag) {
				if (a) {
					v[i] = '-';
					a--;
				}
				else {
					v[i] = '_';
					b--;
				}
			} else {
				if (b) {
					v[i] = '_';
					b--;
				}
				else {
					v[i] = '-';
					a--;
				}
			}
			flag ^= 1;
		}
	} else {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (flag) {
				if (a) {
					v[i] = '-';
					a--;
				}
				else {
					v[i] = '_';
					b--;
				}
			} else {
				if (b) {
					v[i] = '_';
					b--;
				}
				else {
					v[i] = '-';
					a--;
				}
			}
			flag ^= 1;
		}
	}

	int ans = 0;
	for (int i =0; i < n;i++) {
		if (v[i] == '_' && 
			i-1 >= 0 &&
			i+1 < n &&
			v[i-1] == '-' &&
			v[i+1] == '-') {
			ans += 1 + max(0, c-2);
		}
	}
	cout << ans << endl;
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