#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

vector<int> v(3);
void solve() {
	cin >> v[0] >> v[1] >> v[2];
	
	sort(v.begin(), v.end());
	int x = v[0], y = v[2];
	int ans = 0x3f3f3f3f;
	for (int i = x; i<=y;i++) {
		int d = abs(v[0] - i) + abs(v[1] - i) + abs(v[2] - i);
		ans = min(ans, d);
	}
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