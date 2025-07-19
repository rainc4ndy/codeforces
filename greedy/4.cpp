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
	int m,n;
	cin >> m >> n;

	vector<P> v(n);
	vector<bool> vb(n+1);
	for (int i = 0; i < n; i++)
		cin >> v[i].x;

	for (int i = 0; i < n; i++)
		cin >> v[i].y;

	sort(begin(v), end(v), [&](P&a, P&b) {
		if (a.y == b.y)
			return a.x < b.x; //time
		return a.y > b.y; //pen
	});

	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = v[i].x; j >= 1; j--) {
			if (!vb[j]) {
				vb[j] = flag = true;
				break;
			}
		}
		if (!flag) {
			m -= v[i].y;
		}
	}
	cout << m;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}