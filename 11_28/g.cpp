#include <bits/stdc++.h> 
#include <cstdlib>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	
	int n,m;
	cin >> n >> m;
	if (n & 1) {
		if (!(m & 1)) {
		cout << "Y";

		} else {
			srand(time(0));
		 if (rand() % 2 == 0) cout << 'Y';
		 else cout << 'N';	
		}
	} else {
		if (m & 1) {
			cout << "N";
		} else {
		srand(time(0));
		 if (rand() % 2 == 0) cout << 'Y';
		 else cout << 'N';	
		}
	}
/*
	srand(time(0));
	if (rand() & 1) cout << 'Y';
	else cout << 'N';*/
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _  = 1;
	while(_--) solve();

	return 0;
}