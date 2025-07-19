#include <iostream>
#include <cstring>
#include <string>

int main(int argc, char const *argv[]) {	

	using namespace std;
	string s1, s2;
	std::getline(cin, s1);
	std::getline(cin, s2);

	int result = stricmp(s1.c_str(), s2.c_str());

	if (result != 0) {
		result = (result > 0) ? 1 : -1;
	}

	cout << result;

	return 0;
}