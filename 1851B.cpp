#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (200001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod];
ll v2[mod];
void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v2[i] = v[i];
	}

	sort(v, v + n);
	for (int i = 0; i < n; i++) {
		if (v2[i] % 2 != v[i] % 2) {
			cout << "no" << endl;
			return;
		}
	}
	cout << "yes" << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t; 

	cin >> t;
	
	while (t--) {
		solve();
	}

	return 0;
}