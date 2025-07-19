#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int n, m;
	cin >> n >>m;

	map<string, string> lan1;
	map<string, string> lan2;

	string t1, t2, t3;

	for (int i = 0; i < m; ++i){
		cin >> t1 >> t2;
		lan1.insert(pair<string, string>(t1, t2)); //professor
		lan2.insert(pair<string, string>(t2, t1)); //me
	}

	stringstream ss;
	for (int i = 0; i < n; ++i) {
		cin >> t3;
		cout << "\"" << t3 << "\"" << endl;
		if (lan2.count(t3) <= 0) { //does not exist in my language
			ss << lan1[t3];
		} else{
			ss << t3;
		}
		if (i != n - 1) {
			ss << ' ';
		}
	}
	cout << ss.str();

	return 0;
}