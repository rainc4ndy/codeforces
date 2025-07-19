#include <bits/stdc++.h>
using namespace std;

#define SZ (256)

struct st {
	int sc[SZ];
	int sz;
	st(): sc(), sz(0) {}
};

void DisplayStudents(st* ptr) {
	for(unsigned i = 0; i < ptr->sz; ++i) {
		cout << "id: " << i
			<< "    score: " << ptr->sc[i] << endl;
	}
}

int main() {

	st tmp;
	cout << "num of students: ";
	cin >> tmp.sz;

	cout << "scores: ";
	for(unsigned i = 0; i < tmp.sz; ++i)
		cin >> tmp.sc[i];

	int ans = 0;
	for(unsigned i = 0; i < tmp.sz; ++i)
		ans = tmp.sc[i] > 90 ? ans + 1 : ans;

	DisplayStudents(&tmp);

	cout << "num of students whose score above 90 is: "
		<< ans;

	return 0;
}
