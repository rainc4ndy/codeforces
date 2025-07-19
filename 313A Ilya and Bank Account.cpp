#include <algorithm>
#include <bits/stdc++.h> 
#include <sstream>

#define mod (100001)
#define ll long long 

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	ll num;
	cin >> num;

	stringstream ss;
	ss << num;
	string s = ss.str();

	if (s[0] == '-') {
		//delete the bigger digit
		
		char i = l <= 2 ? max(s[l-1], s[l-2]) : min(s[l-1], s[l-2]);

		s[l-2] = i;
		s[l-1] = '\0';
	}

	ss.str("");
	ss << s;
	int ans;
	ss >> ans;
	cout << ans;

	return 0;
}