#include <bits/stdc++.h>
using namespace std;

struct st {
	unsigned int age;
	string name;
	char sex;
	float score[3];
};

int main() {

	st a;
	cout << "student name:";
	getline(cin, a.name);

	cout << "age:";
	cin >> a.age;

	while (a.sex != 'M' && a.sex != 'F') {
		cout << "sex (M/F): ";
			cin >> a.sex;
	}

	cout << "academic performance (math, C, pe):";
	for(unsigned i = 0; i < 3; ++i)
		cin >> a.score[i];

	cout << "average score: "
		<< (a.score[0] + a.score[1] + a.score[2]) / 3;

	return 0;
}
