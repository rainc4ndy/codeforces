#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<ll, ll> P;

void solve() {
	ll n,m,L;
	cin >> n >> m >> L;

	vector<P> b(n), p(m);
	for (int i = 0; i < n; i++) {
		cin >> b[i].x >> b[i].y;
	}
	for (int i = 0; i < m; i++) {
		cin >> p[i].x >> p[i].y;
	}

	auto cmp = [](P&a, P&b) { 
		return a.y < b.y; 
	};
	priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

	int x = 0, power = 1, ans = 0;
	for (int i = 0; i < n; i++) {
		while (p[x].x < b[i].x && x < m) {
			pq.push(p[x++]);
		}
		while (power < b[i].y - b[i].x + 2) {
			if (!pq.empty()) {
				power += pq.top().y;
				pq.pop();
				ans++;
			} else {
				cout << -1 << endl;
				return;
			}
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