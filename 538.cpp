#include <bits/stdc++.h> 
#include <sstream>
#include <string>
#include <vector>
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

	map<int, int> ans;
	int tot = 0;
	auto f = [&](const auto& self, int n) -> void {
		if (n == 0) {
			return;
		}


		stringstream ss;
		ss << n;
		string s = ss.str();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '0' && s[i] != '1') {
				s[i] = '1';
			}
		}
		stringstream ss2(s);
		int num;
		ss2 >> num;

		ans[num] += 1;
		tot += 1;
		self(self, n - num);
	};
	f(f, n);

	cout << tot << endl;
	for (auto& it : ans) {
		for (int i = 0; i < it.y; i++) cout << it.x << ' ';
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}