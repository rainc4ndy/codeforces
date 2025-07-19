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
	map<int, int> um;
	for (int i = 0; i < n;i++) {
		cin >> v[i];
		um[v[i]]++;
	}

	int ans = 0;
	for (auto& it : um) {
		if (it.y > 1) {
			ans += it.y / 2;
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