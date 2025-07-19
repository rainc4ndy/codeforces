#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<ll, ll> P;


std::set<P> ps;
void solve() {
	ps.clear();
	ll n,m;
	cin >> n >> m;

	vector<ll> v(n), d(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		cin >> d[i];

	auto work = [&](int i) {
		int cx = v[i], R = d[i];
        for (int x = -R; x <= R; ++x) {
            int maxY = std::floor(std::sqrt(R * R - x * x));
            for (int y = -maxY; y <= maxY; ++y) {
                ps.insert({cx + x, y});
            }
        }
	};

	for (int i = 0; i < n; i++) {
		work(i);
	}
    cout << ps.size() << endl;
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