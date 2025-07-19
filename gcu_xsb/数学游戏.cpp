#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	bool flag = true;
	for (int i = n-1;i>=0; i--) {
		if (flag) {
			if (++v[i] >= 10) {
				v[i] = 0;
			} else {
				flag = false;
			}
		}
	}

	if (flag) {
		v.insert(begin(v), 1);
	}
	for (auto& it : v )
		cout << it << ' ';
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}