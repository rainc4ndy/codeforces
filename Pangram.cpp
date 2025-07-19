#include <bits/stdc++.h> 
#include <cctype>
#include <ios>
 
#define mod (100001)
#define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int tmp;
    cin >> tmp;
	string s;
	cin >> s;

	bool d[mod] {};

	int l = s.length();
	for (int i = 0; i < l; i++) {
		d[(int)s[i]] = true;
		if (isupper(s[i]))
			d[toupper(s[i])] = true;
	}

	for (int i = (int)'a'; i <= (int)'z'; i++) {
		if (!d[i] && !d[toupper(i)]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}