#include <bits/stdc++.h> 
#include <string>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	string s;
	std::getline(cin, s);
	int r =0;
	for (auto it : s) {
		if (it !=' ')
			r++;
	}
	cout << r;

	return 0;
}