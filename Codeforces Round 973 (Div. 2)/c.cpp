#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string password_0 = ""; //先猜0的
		int first = -1; //记录第一次猜错的位置
		bool rev = false;
		for (int i = 0; i < n; ++i) {
			string a0;
			if (rev) {
				a0 = password_0;
				a0.insert(begin(a0), '0');
			} else a0 = password_0 + '0';

			cout << "? " << a0 << endl;
			fflush(stdout);
			int rep;
			cin >> rep;

			if (rep == 1) {
				if (rev) {
					password_0.insert(begin(password_0), '0');
				} else {
					password_0 += '0';
				}
			} else {
				if (rev) {
					password_0.insert(begin(password_0), '1');
				} else {
					//猜错了
					a0 = password_0 + '1';
					cout << "? " << a0 << endl;
					fflush(stdout);
					int rep;

					cin >> rep;
					//还是错了
					if (!rep) {
						rev = true;
						i--;
					} else {
						password_0 += '1';
					}
				}
			}
		}
		cout << "! " << password_0 << endl;
		fflush(stdout);
	}
	return 0;
}
