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
	int c1, c2, k;
	cin >> c1 >> c2 >> k;

	vector<P> ans(k+1);
	for (int i = 1; i <= k; i++) {
		ans[i].x = c1;
		ans[i].y = c2;
	}

	for (int i = 1; i <= k / 2; i++) {
		ans[i].x += i;
		ans[k-i+1].x -= i;

		ans[i].y += i;
		ans[k-i+1].y -= i;
	}

	for (int i = 1; i <= k; i++) {
		cout << ans[i].x << ' ' << ans[i].y << endl;
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