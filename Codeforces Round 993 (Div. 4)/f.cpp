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
	int n,m,q;
	cin >> n >> m >> q;

	vector<int> v(n),d(m);
	vector<vector<int>> graph(n,vector<int>(m));
	//vector<int> arr;


	for (int i = 0; i < n; i++) 
		cin >> v[i];

	for (int i = 0; i < m; i++)
		cin >> d[i];

	int sum = 0;
	for (int i = 0; i < n; i++)  {
		for (int j = 0; j < m; j++) {
			graph[i][j] = v[i] * d[j];
			//arr.push_back( v[i] * d[j]);
			sum +=  v[i] * d[j];
		}		
	}

	//sort(begin(arr), end(arr));

	cout << "sum = " << sum << endl;
	//for (auto it : arr) cout << it << ' ';
	//cout << endl;

	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
	}
	cout << "ok" << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}