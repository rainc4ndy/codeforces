#include <iostream>

#define mod (101)

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int n, a[mod] {} , b[mod] {}, c[mod] {};

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	for (int i = 0; i < n; i++) {
		if (c[i] == a[i] * b[i]) {

			cout << "Lv Yan";
		}
		else if (c[i] == (a[i] + b[i])) {
			cout << "Tu Dou";
		}
		else {
			cout << "zhe du shi sha ya!";
		}
		if (i != n - 1)
			cout << endl;
	}

	return 0;
}