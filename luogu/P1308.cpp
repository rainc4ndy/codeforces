#include <bits/stdc++.h> 

int main() {

	using namespace std;
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	string s1, s2;
	cin >> s1;
	cin.ignore();
	std::getline(cin, s2);

	for (int i = 0; i < s1.length(); i++)
		s1[i] = tolower(s1[i]);

	for (int i = 0; i < s2.length(); i++)
		s2[i] = tolower(s2[i]);

	int pos = 0;
	bool b1, b2;
	int count = 0;
	int rec= 0;
	while ((pos = s2.find(s1, pos)) != string::npos) {
		//cout << "s2 = " << s2 << endl;
		b1 = b2 = false;
		if (pos == 0)
			b1 = true;
		if (pos == s2.length() - 1)
			b2 = true;

		if (!b1) {
			if (s2[pos - 1] == ' ')
				b1 = true;
		}
		if (!b2) {
			if (s2[pos + s1.length()] == ' ')
				b2 = true;
		}

		if (b1 && b2) {
			count++;
			if (count == 1)
				rec = pos;
		}

		pos += s1.length();
	}

	if (count == 0) {
		cout << -1;
		return 0;
	}

	cout << count << ' ' << rec;

	return 0;
}