#include <bits/stdc++.h>
using namespace std;

const int SZ = 64;
int len = SZ;
int a[SZ] {};

void out() {
	for (unsigned i = 0; i < len; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void del_zero() {
	int cnt = 0;
	for (unsigned i = 0; i < len; i++) {
		if (a[i] == 0)
			cnt++;
		else
			a[i - cnt] = a[i];
	}
	len -= cnt;
}

int main() {
	for (unsigned i = 0; i < SZ; ++i)
		a[i] = i % 4 == 0 ? 0 : i;

	cout << "len = " << len << endl;
	out();
	del_zero();
	cout << "len = " << len << endl;
	out();
	return 0;
}
