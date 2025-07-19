#include <algorithm>
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
	int n; string s;
	cin >> n >> s;

	vector<int> v(512, 0);
	for (int i=0;i<n;i++) {
		v[s[i]]++;
	}

	int mi = 0x3f3f3f3f; char mic;
	int mx = 0; char mxc;
	for (int i = 0; i < 512; i++) {
		if (v[i] < mi && v[i] != 0) {
			mi = v[i], mic = i;
		}
		if (v[i] > mx) {
			mx = v[i], mxc = i;
		}
	}

	for (int i=0;i<n;i++) {
		if (s[i] == mic) {
			string tmp = s;
			tmp[i] = mxc;
			if (tmp != s) {
				s = tmp;
				break;
			} else {
				cout <<"fail" << endl;
			}
		}
	}

	cout << s << endl;
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