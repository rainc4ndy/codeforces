#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int num;
	cin >> num;

    int rec[2] {};

	for (int i = 0; i < num; i++) {
		char c;
		cin >> c;
		if (c == 'A')
			rec[0]++;
		else
			rec[1]++;
	}

	if (rec[0] == rec[1])
		cout << "Friendship";
	else if (rec[0] > rec[1])
		cout << "Anton";
	else
		cout << "Danik";

	return 0;
}