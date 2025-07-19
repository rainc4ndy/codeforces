#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;


void solve() {
	int n,k;
	cin >> n >> k;

	int sum = 0;
	int ans = 0;
	std::vector<int> v(n);
	for (int i =0; i <n;i++) cin >> v[i];

	for (int i =0;i <n;i++) {
		if (v[i] >= k) {
			sum += v[i];
		} else if (v[i] == 0 && sum) {
			sum--,ans++;
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