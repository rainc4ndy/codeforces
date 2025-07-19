#include <bits/stdc++.h> 
#include <string>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	string s;
	std::getline(cin, s);

	int v[256], dd = 1;
	for (int i = 'a'; i <= 'z'; i++) {
		v[i] = dd++;
		if (i != 'r' && i != 'y') {

			if (dd > 3)
				dd = 1;
		} else {
			if (dd > 4)
				dd = 1;
		}

	}

	int ans = 0;

	for (auto it : s) {
		if (it != ' ')
			ans += v[(int)it];
		else ans++;
	}

	cout << ans;

	return 0;
}