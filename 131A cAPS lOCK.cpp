#include <cctype>
#include <ios>
#include <iostream>
#include <string>

//either it only contains uppercase letters;
//or all letters except for the first one are uppercase.

enum {
	FIND_UP_ONLY,
	FIND_SEC
};

bool is_upper(char c) {
	return 'A' <= c && c <= 'Z';
}

bool is_lower(char c) {
	return 'a' <= c && c <= 'z';
}

int main(int argc, char const *argv[]) {
	
	using namespace std;

	string s;
	getline(cin, s);

	int len = s.length();
	int ups = 0;
	int front = 0, rear = 0;
	int mode = FIND_UP_ONLY;
	bool flag = false;

	//see all uppercases as segments
	for (int i = 0; i < len; ++i) {	
		cout << "rear = " << rear << " front = " << front << endl;

		if (!flag) {
			if (is_upper(i)) {
				mode = FIND_UP_ONLY;
			} else {
				mode = FIND_SEC;
			}
			front = rear = i;
			flag = true;
		} else {

			if (mode == FIND_UP_ONLY) {
				if (is_upper(i)) {
					front++;
					//lianxu daxie
				} else {
					for (int j = rear; j < front; j++) {
						s[j] = std::tolower(s[j]);
					}
					flag = false;
				}
			} else {
				//cAPS
				if (is_upper(i)) {
					front++;
					//lianxu daxie
				} else {
					for (int j = rear; j < front; j++) {
						s[j] = std::tolower(s[j]);
					}
					flag = false;
				}
			}

		}

	}

	cout << s;

	return 0;
}