#include <bits/stdc++.h> 
using namespace std;

const int mod = 5e6+1;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int n, k, ans = 0;
int v[100] {};
bool vis[100] {};

bool f(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void dfs(int cur_sum, int length, int i) {
	if (length == k) {
		if (f(cur_sum)) {
			ans++;
			return;
		}
	}
	
	for (; i < n; i++) {
		if (vis[i])
			continue;
		vis[i] = true;
		dfs(cur_sum + v[i], length+1, i+1);
		vis[i] = false;
	}
}

void solve() {
	cin >> n >> k;

	for (int i = 0; i < n; i++ ) {
		cin >> v[i];
	}

	dfs(0, 0, 0);
	cout << ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    solve();
	return 0;
}