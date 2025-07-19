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

	ll xx;
	vector<ll> d(n, 0);
	vector<vector<ll>> graph(n+2, vector<ll>());
	for (int i = 1; i <= n; i++){
		cin >> xx;
		graph[i+1].emplace_back(xx);
		graph[xx].emplace_back(i+1);
	}

	vector<ll> sum(n+2, 0);
	auto get_layer_sum = [&](const auto& self, ll pa) -> void {

		for (auto ch : graph[pa]) {
			
		}
	};

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