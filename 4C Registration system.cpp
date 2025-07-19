#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

struct user {
	std::string s;
	bool edited;
};

int main(int argc, char const *argv[]) {

	using namespace std;

	//code
	int num = 0;
	cin >> num;

	std::unordered_map<string, int> m; //record
	std::vector<user> v;

	int c = 0;
	string s;
	user u { s, true };
	for (int i = 0; i < num; ++i) {
		cin >> s;

		c = 0;
		if (m.count(s) > 0)
			c = m[s];
		if (c > 0) {
			stringstream ss;
			ss << c;
			m[s] += 1; //origin
			s.append(ss.str());


			u.s = s;
			u.edited = true;
			v.push_back(u);
			//m[s] += 1; //edited
		} else {
			u.s = s;
			u.edited = false;
			v.push_back(u);
			m[s] += 1;
		}
	}

	//cout << "##################" << endl;

	for (int i = 0; i < num; ++i) {
		if (v[i].edited) {
			cout << v[i].s;
		} else {
			cout << "OK";
		}
		if (i != num - 1) {
			cout << endl;
		}
	}

	return 0;
}
