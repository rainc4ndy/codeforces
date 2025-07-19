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
	int n;
	cin >> n;
	vector<int> v(n), ans(n);
	vector<bool> vis(n+1, false);
	for (int i =0;i < n;i++) {
		cin >> v[i];
	}

	int num = 1;
	for (int i =0;i < n;i++) {
		if (!vis[v[i]]) {
			ans[i] = v[i];
			vis[v[i]] = true;
		} else {
			for (; num <= n; num++) {
				if (!vis[num]) {
					ans[i] = num;
					vis[num] = true;
					break;
				}
			}
		}
	}

	for (int i =0;i < n;i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
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