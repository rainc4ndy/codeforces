#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n; 
	cin >> n;

	string s1, s2;

	set<string> u1,u2;
	char c;
	for (int i = 0 ; i < n; i++) {
		cin >> s1 >> c >> s2;
		u1.insert(s1);
		u2.insert(s2);
	}

	bool flag = false;
	bool nxt = false;
	for (auto it : u2) {
		flag = false;
		
		if (!u1.count(it)) {
			if (nxt) {
				cout << endl;
			}
			for (auto yt : u1) {
				if (yt > it) {
					cout << it << " - " << yt;
					flag = true;
					break;
				}
			}
			if (!flag ) {
				cout << it << " - " << "23:59:59";
			}
			nxt = true;

		} 
	}
 
	return 0;
}