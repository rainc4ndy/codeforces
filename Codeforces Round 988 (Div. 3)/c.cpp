#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

bool f(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve() {
	ll n;
	cin >> n;

	// 1 3 2
	ll lst = 0;
	vector<ll> perm;
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			perm.push_back(i);
			lst = i;
		}
	}
	ll st = -1;
	for (int i = 1; i <= n; i++) {
		if (!(i & 1)) {
			if (!f(lst + i)) {
				st = i;
			}
 		}
	}
	if (st == -1) {
		cout << -1 << endl;
	} else {
		for (auto& it : perm) cout << it << ' ';
		cout << st << ' ';
		for (int i = 1; i <= n; i++) {
			if (!(i & 1) && i != st) {
				cout << i << ' ';
			}
		}
		cout << endl;
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