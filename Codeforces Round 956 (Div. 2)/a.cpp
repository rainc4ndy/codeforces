#include <bits/stdc++.h> 
using namespace std;

const int mod = 101;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << i << ' ';
	}
	cout << endl;
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