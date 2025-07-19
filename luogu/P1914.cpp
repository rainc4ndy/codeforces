#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	string s;
	cin >> n >> s;

	for (auto it : s) {
		char c = it -'a';
		c = (c+n) % (26);
		cout << (char)(c+'a');
	} 

	return 0;
}