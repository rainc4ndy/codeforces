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
	vector<P> v(n);

	for (int i =0;i<n;i++) {
		cin >> v[i].x >> v[i].y;
	}

	for (int i =0;i<n;i++) {
		if (v[i].y < 0 && abs(v[i].y) > 1) {
			cout << "NO" << endl;
		} else cout << "YES" << endl;
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}