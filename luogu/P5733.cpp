#include <bits/stdc++.h> 
#include <cctype>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	string s;
	cin >> s;
	for (auto it :s)
		cout << (char)toupper(it);

	return 0;
}