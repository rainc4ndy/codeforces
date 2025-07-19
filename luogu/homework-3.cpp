#include <bits/stdc++.h>
using namespace std;

void sub(double *pa, double* pb, double *pd) {
	*pd = *pa - *pb;
}

int main() {

	double a, b, c, d;
	double  *pa = &a,
			*pb = &b,
			*pc = &c,
			*pd = &d;

	cout << "value of a and b: ";
	cin >> a >> b;

	*pc = a + b;
	cout << *pc << endl;

	sub(pa, pb, pd);
	cout << "d: " << *pd;
	return 0;
}
