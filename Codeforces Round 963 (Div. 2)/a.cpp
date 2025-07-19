#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

char v[1024];
int cnt[1024];
void solve() {
	int n;
	cin >> n;

	memset(cnt, 0 ,sizeof(cnt));

	for (int i = 0; i < n*4; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}

	int ans = n*4;

	if (cnt['A'] < n)
		ans -= abs(n - cnt['A']); 
	if (cnt['B'] < n)
		ans -= abs(n - cnt['B']); 
	if (cnt['C'] < n)
		ans -= abs(n - cnt['C']); 
	if (cnt['D'] < n)
		ans -= abs(n - cnt['D']); 
	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}