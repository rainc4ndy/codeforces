#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod];

void solve() {
	int n;
	cin >>n;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	if (n == 1) {
		cout << 0 << endl;
		return;
	}

	int last = 1;
	int ans = 0;
	if (v[1] < v[0]) {
		if (v[1] == 1) {
			cout << -1 << endl;
			return;
		}
		last = (int)ceil(log(v[0]) / log(v[1]));
		ans++;
	}

	for (int i = 2; i < n; i++) {
		if (v[i] == 1 && v[i-1] != 1) {
			cout << -1 << endl;
			return;
		}
		if (v[i] < v[i-1]) {
			last = (int)ceil(last * log(v[i-1]) / log(v[i]));
		    while (((last & (last - 1)) != 0)) {
		        last++;
		    }
		    int d = log2(last);
			ans += d;
		}
	}

	cout << ans << endl;
}
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
    while (t--) solve();    

    return 0;
}
