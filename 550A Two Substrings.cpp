#include <algorithm>
#include <bits/stdc++.h> 
#include <string>

using namespace std;
bool findABBA(string s) {
	int r1 = 0, r2 = 0;

	r1 = s.find("AB");
	if (r1 == string::npos) {
		return false;
	}

	r2 = s.substr(r1 + 2, s.length()).find("BA");
	if (r2 == string::npos) {
		return false;
	}

	return true;
}

bool findBAAB(string s) {
	int r1 = 0, r2 = 0;

	r1 = s.find("BA");
	if (r1 == string::npos) {
		return false;
	}

	r2 = s.substr(r1 + 2, s.length()).find("AB");
	if (r2 == string::npos) {
		return false;
	}

	return true;
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	string s;
	cin >> s;

	if (!findABBA(s)) {
		if (!findBAAB(s)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}