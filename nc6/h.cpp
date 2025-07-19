#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	string s;
	cin >> s;

	int sz =s.size();
	
	int up = sz / 10;
	int rem = sz % 10;

	for (int i = 0; i < up; i += 10) {
		bool ok = false;
		for (int j = i; j < i + 10; j++) {
			if (s[j] != '3') {
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "invalid" << endl;
			return;
		}
	}

	int up2 = sz / 90;

	for (int i = 0; i < up2; i += 90) {
		bool ok = false;
		for (int j = i; j < i + 90; j++) {
			if (s[j] != '5' || s[j] == 'U') {
				ok = true;
			}
			break;
		}
		if (!ok) {
			cout << "invalid" << endl;
			return;
		}
	}

	cout << "valid" << endl;


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