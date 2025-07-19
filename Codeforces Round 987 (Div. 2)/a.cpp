#include <bits/stdc++.h> 
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
	vector<int> v(n);

	map<int,int> m;
	int mx = 0, mx_cnt = 0;
	for (int i =0;i<n;i++) {
		cin >> v[i];
		m[v[i]]++;
		if (m[v[i]] > mx_cnt) {
			mx_cnt= m[v[i]];
			mx = v[i]; 
		}
	}
	cout << n - mx_cnt << endl;
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