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
	vector<int> b(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	
	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		b[i] = c-'0';
	}

	auto check_l = [&](int l) -> bool {
		for (int i = 0; i < n; i++) {
			if (b[i] == 1) {
				if (v[i] < l &&
					v[i-1] < l &&
					v[i-2] < l &&
					v[i-3] < l &&
					v[i-4] < l &&
					b[i-1] == 0 &&
					b[i-2] == 0 &&
					b[i-3] == 0 &&
					b[i-4] == 0) {

					// pass
				} else {
					
				}
			} 
		}
		return
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