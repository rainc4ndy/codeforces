#include <bits/stdc++.h> 

 
using namespace std;

int main() {
    

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 


    int one[11];

	int t;
	cin >> t;

	vector<bool> ans(t);

	int n; 
	string s;
	bool ig = false;

	for (int i = 0; i < t; i++) {
		cin >> n;
		ig = false;
		memset(one, 0, sizeof(int) * n);

		for (int j = 0; j < n; j++) { //r 
			cin >> s;
			if (ig)
				continue;
			for (int k = 0; k < n; k++) { //c
				if (s[k] == '1') {
					one[j]++;
				}
			}
			if (j != 0 && one[j] != 0) {
				if (one[j] == one[j - 1]) {
					ans[i] = true; //sq
					ig = true;
				}
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cout << (ans[i] ? "SQUARE" : "TRIANGLE");
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}