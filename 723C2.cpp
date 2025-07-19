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
	vector<ll> v(n+1);
	for (int i = 1; i <= n;i++)
		cin >> v[i];

	vector<vector<int>> dp(n+1, vector<int>(n+1));

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			dp[]
		}
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	//cin >> _;
	while(_--) solve();

	return 0;
}