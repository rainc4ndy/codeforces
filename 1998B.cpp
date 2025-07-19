#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod];

void solve() {
	int n;
	cin >> n;
	for (int i =0;i<n;i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
		cout << v[i % n] << ' ';
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