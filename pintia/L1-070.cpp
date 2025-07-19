#include <bits/stdc++.h> 
#include <string>
#include <variant>

#define mod (100001)
#define ll long long
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    std::vector<string> v;

	string line;
	while (true) {
		std::getline(cin, line);
		if (line.length() == 1 && line[0] == '.') 
			break;
		v.push_back(line);
	}

	int c = 0;

	int f = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].find("chi1 huo3 guo1") != string::npos) {
			if (c == 0)
				f = i;
			c++;
		}
	}

	cout << v.size() << endl;
	if (c == 0)
		cout <<  "-_-#";
	else 
		cout << f + 1 << ' ' << c;

	return 0;
}