#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int d = m;
	for (int i = n-1; i >= 0; i--) {
		int x = d % 10;
		v[i] += x;
		d /= 10;
		if (v[i] >= 10 && i > 0) {
			v[i] %= 10;
			v[i-1]++;
		}
	}
	for (auto it : v)
		cout << it;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}