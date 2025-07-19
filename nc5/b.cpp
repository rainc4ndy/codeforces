#include <bits/stdc++.h> 
using namespace std;


const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,m,a,b;
	cin >> n >> m >> a >> b;

	if (a && b) {
		cout << "No" << endl;
		return;
	}	
	else if (a == 0 && b == 1) {	
		if (n % 2!= 0 || n % 2!= 0) {
			cout << "No" << endl;
			return;
		}
		cout << "Yes" << endl;
	}
	else if (a == 1 && b == 0) {	
		if (n % 2!= 0 || n % 2!= 0) {
			cout << "No" << endl;
			return;
		}
		cout << "Yes" << endl;
	}
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