#include <iostream>
#include <algorithm>

struct student {
	int score;
	int pta;
};

bool cmp(student& a, student& b) {
	return a.score > b.score;
}

bool cmp2(student& a, student& b) {
	return a.pta > b.pta;
}

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int num, k, s;

	//s: pta
	cout << "T: ";

	cin >> num >> k >> s;

	student v[100001] {};

	for (int i = 0; i < num; i++) {
		cin >> v[i].score >> v[i].pta;
	}


	sort(&v[0], &v[mod - 1], cmp);


	int end = 0;
	while (v[end].score >= 175) 
		end++;

	sort(&v[0], &v[end - 1], cmp2);

	end = 0;
	while (v[end].pta >= s) 
		end++;

	cout << end;

	return 0;
}