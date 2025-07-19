#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int y = 0;

	cin >> y;

	int t = y + 1;
	
	while (true) {
		stringstream ss;

		ss << t;
		string s = ss.str();

		//cout << "t = " << s << endl;

		int l = s.size();
		bool flag = false;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				if (i == j)
					continue;
				if (s[i] == s[j]) {
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag)
			break;

		t++;
	}

	cout << t;

	return 0;
}