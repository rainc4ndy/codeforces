#include <cstring>
#include <iostream>
#include <algorithm>

//Count the minimum number of stones to take from the table 
//so that any two neighboring stones had different colors.

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int n;
	string s;

	cin >> n >> s;

	bool *flags = new bool[s.length()]; //record of "deleted" elements
	memset(flags, 0, s.length() * sizeof(bool));

	int st = 0;
	for (int i = 0; i < s.length(); i++) {
		int sl = max(i - 1, 0), 
			sr = min(i + 1, (int)s.length() - 1);

		if (s[sl] == s[i] && sl != i && !flags[sl]) {
			st++;
			flags[i] = true;
			continue;
		}
		if (s[sr] == s[i] && sr != i && !flags[sr]) {
			st++;
			flags[i] = true;
			continue;
		}
	}

	cout << st;

	delete[] flags;

	return 0;
}