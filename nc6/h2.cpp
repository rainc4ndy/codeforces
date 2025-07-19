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
	char cnt[256] {};

	int sz =s.size();
	
	int l = 0, r = 0;
	while (r < sz) {
		if (r - l == 10) {
			if (cnt['4'] == 0 && 
				cnt['5'] == 0 &&
				cnt['U'] == 0)
			{
				cout << "invalid" << endl;
				return;
			}
			cnt[s[l]]--; 
			l++;
		}
		cnt[s[r]]++; 
		r++;
	}

	l = 0, r = 0;
	while (r < sz) {
		if (r - l == 90) {
			if (
				cnt['5'] == 0 &&
				cnt['U'] == 0)
			{
				cout << "invalid" << endl;
				return;
			}
			cnt[s[l]]--; 
			l++;
		}
		cnt[s[r]]++; 
		r++;
	}

	bool ok = false; int left = -1;
	for (int i = 0; i < sz; i++) {
		if (s[i] == 'U' && left != -1) {
			ok = true;
		}
		if (s[i] == '5' && left == -1) {
			left = i;
		} else if (s[i] == '5' && left != -1) {
			if (!ok) {
				cout << "invalid" << endl;
				return;
			} else {
				ok = false; left = -1;
			}
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