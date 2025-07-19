#include <bits/stdc++.h> 
#include <vector>
 
using namespace std;

int main() {
    

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	vector<bool> ans(n); 

	string s;

	int as = 0, bs = 0;

	for (int i = 0; i < n; i++) {
		cin >> s;
		as = 0, bs = 0;
		for (int j = 0; j < 5; j++) {
			if (s[j] == 'A')
				as++;
			else bs++;
		}
		ans[i] = as > bs;
	}

	for (int i = 0; i < n; i++) {
		cout << (ans[i] ? 'A' : 'B');
		if (i != n - 1)
			cout << endl;
	}

	return 0;
}