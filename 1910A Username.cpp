#include <bits/stdc++.h> 

//Username is a string consisting of lowercase Latin letters and/or digits, 
//which contains at least one letter. 
//For example, user0, 1fox1, zzzz are correct usernames, but 1337 and User22 are not.

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	vector<string> ans;

	string s;

	int ptr = 0;
	int l = 0;
	bool dflag = false;
	for (int i = 0; i < t; i++) {
		cin >> s;

		l = s.length();
		for (int j = 0; j < l; j++) {
			if (isdigit(s[j])) {
				if (!dflag) {
					dflag = true;
					ptr = j;
				}

				//last
				if (j == l - 1) {
					ptr = s[ptr] == '0' ? ptr + 1 : ptr;
					ans.push_back(s.substr(0, ptr));
				}
			} else {
				dflag = false;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];

		if (i != t - 1)
			cout << endl;
	}
	return 0;
}