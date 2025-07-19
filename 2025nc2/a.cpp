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
	vector<bool> flags(8, false);
	int n;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		flags[n] = 1;
	}
	for (int i = 1; i <= 7; i++) {
		if (flags[i]) {
			if (i == 4 || i == 7) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
} 