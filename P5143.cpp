#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	double n;
	cin >> n;
	vector<vector<double>> v(n, vector<double>(3));
	for (int i = 0;i < n;i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}	

	std::sort(begin(v), end(v), [&](vector<double>&a, vector<double>&b) {
		return a[2] < b[2];
	});


	double ans = 0;
	for (int i = 0; i < n-1; i++) {
		ans += sqrt(
			(v[i][0]-v[i+1][0])*(v[i][0]-v[i+1][0]) + 
			(v[i][1]-v[i+1][1])*(v[i][1]-v[i+1][1]) +
			(v[i][2]-v[i+1][2])*(v[i][2]-v[i+1][2])
		);
	}

	cout << setprecision(3) << fixed << ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}