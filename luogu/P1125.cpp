#include <bits/stdc++.h> 
#include <unordered_map>
 
using namespace std;

bool f(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	string s;
	cin >> s;
	unordered_map<char, int> m;

	int mx = 0;

	for (auto it : s) {
		m[it]++;
		mx = max(mx , m[it])
	}
	int mi = 0x3f3f3f3f;
	
	for (auto it : m) {
		if (it.second == 0)
			continue;
		mi = min(mi, it.second);
	}
	if (f(mx - mi)) {
		cout << "Lucky Word" << endl << mx - mi;
	} else {
		cout << "No Answer" << endl << 0;
	}

	return 0;
}