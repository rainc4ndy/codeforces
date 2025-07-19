#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

char vs[mod];
char vt[mod];

void solve() {
	int n;

	cin >> n;
	int f0 = 0x3f3f3f3f;
	int f1 = 0x3f3f3f3f;
	for (int i =0;i<n;i++) {
		cin >> vs[i];
		if (vs[i] == '0' && f0 == 0x3f3f3f3f)
			f0 = i;
		if (vs[i] == '1' && f1 == 0x3f3f3f3f)
			f1 = i;
	}
	for (int i =0;i<n;i++) {
		cin >> vt[i];
	}
	
	for (int i =0;i<n;i++) {
		if (vs[i] != vt[i]) {
			if (vs[i] == '1') {
				if (i < f1) {
					cout << "NO" << endl;
					return;
				}
			} else {
				if (i < f1) {
					cout << "NO" << endl;
					return;
				}
			}
		}
	}

	cout << "YES" << endl;
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