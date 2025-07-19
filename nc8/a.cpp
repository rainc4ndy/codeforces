#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};
set<int> um;
set<int> us;

void solve() {
	int n;
	cin >> n;

	int lim = 0x3f3f3f3f;

	us.clear();
	um.clear();

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		us.insert(v[i]);
	}

	int g;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			g = __gcd(v[i], v[j]);
			if (!us.count(g)) {
				um.insert(g);
			}
		}
	}

	if (um.size() == 0) {
		cout << "Haitang" << endl;
		return;
	}

	if (um.count(1)) {
		
	}

	if (um.size() % 2 != 0) {
		
			cout << "dXqwq" << endl;
		} else cout << "Haitang" << endl;
	}
	else {
		if (um.count(1)) {
			cout << "dXqwq" << endl;
		} else cout << "Haitang" << endl;
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