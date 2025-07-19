#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[256];

void solve() {
	string s1,s2;
	cin >> s1 >> s2;

	int ans = s1.length();
	memset(v, 0, sizeof(v));

	for (auto it:s2){
		v[(char)it]++;
	}
	for (int i = 0; i < 256;i++) {
		if (v[i] > 0) {
			int d = 0;
			for (auto it:s1) {
				if (it == i) {
					d++;
					if (d >= v[i])
						break;
				}
			}
			if (d < v[i]) {
				ans += v[i] - d;
			}
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

	while(t--)
		solve();

	return 0;
}