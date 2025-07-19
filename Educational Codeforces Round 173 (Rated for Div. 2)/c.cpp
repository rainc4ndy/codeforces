#include <bits/stdc++.h> 
#include <cstddef>
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
	vector<ll> v(n+1), pa(n+1, 0);
	set<ll> ans = {0};

	for (int i = 1;i <= n;i++) {	
		cin >> v[i];
		pa[i] = pa[i-1] + v[i]; 
	} 


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ll sum = pa[i] - pa[j-1];
			ans.insert(sum);
		}	
	}

	cout << ans.size() << endl;
	for (auto& it : ans) {
		cout << it << ' ';
	}
	cout << endl;
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