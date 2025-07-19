#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

char v[mod] {};
int n;

int make_good(char c, int l, int r) {
	//cout << "l, r = " << l << ' ' << r << endl;
	if (r-l == 1) {
		if (v[l] != c) {
			return 1;
		}
		return 0;
	}

	int mid = (l+r)>>1;
	int p1 = 0, p2 = 0;
	for (int i = l; i < mid; i++) {
		if (v[i] != c) {
			p1++;
		}
	}
	for (int i = mid; i < r; i++) {
		if (v[i] != c) {
			p2++;
		}
	}
	
	int r1 = p1 + make_good(c+1, mid, r);
	int r2 = p2 + make_good(c+1, l, mid);

	return min(r1, r2);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = make_good('a', 0, n);
	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--)
		solve();	

	return 0;
}