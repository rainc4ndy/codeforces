#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t ;
	cin >>t;
	string s;
	vector<string> a(t);
	vector<bool> b(t, false);

	for (int i = 0; i < t;i++) {
		cin >> s;

		int cnt = 0;
		bool ss[256] {};

		for (auto it : s) {
			if (!ss[(int)it]) {
				cnt++;
				ss[(int)it] = true;
			}
		}
		if (cnt > 1 && s.size() > 1) {
			a[i] = s;
			for (int j = 0; j < a[i].size(); j++) {
				for (int q = j; q < a[i].size(); q++) {
					if (a[i][j] != a[i][q]) {
						b[i] = true;
						char tmp = a[i][j];
						a[i][j] = a[i][q];
						a[i][q] = tmp;
						break;
					}
				}
				if (b[i])
					break;
			}
 		}
	}

	for (int i = 0; i < t;i++) {
		if (b[i]) {
			cout << "YES" << endl << a[i];
		} else cout << "NO";

		if (i != t-1)
			cout << endl;
	}


	return 0;
}