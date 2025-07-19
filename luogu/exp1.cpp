#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define LEN 512

const int MAXN = 100000;
vector<int> table(MAXN, 0);

void initTable() {
	for (unsigned i = 2; i < MAXN; ++i) {
		if (table[i] == 0) {
			for (unsigned j = i; j < MAXN; j += i) {
				table[j] = i;
			}
		}
	}
}

void f1() {
	cout << "type a num (num <= 1e6):";
	int num;
	cin >> num;
	if (table[num] == num) {
		cout << "This is a prime number " << endl;
	} else {
		cout << num << '=';
		if (num <= 1) {
			cout << num << endl;
			return;
		}
		bool flag = false;
		while (num != 1) {
			if(flag)
				cout << '*';
			if (table[num] != 1)
				cout << table[num];
			num /= table[num];
			flag = true;
		}
		cout << endl;
	}
}

void f2() {
	cout << "type first term, last term, and tol:";
	int a, b, c;
	cin >> a >> b >> c;

	bool out = true;
	cout << "Do you wish to print the sequence? (Y/n): ";
	char op;
	cin >> op;
	if (op == 'n')
		out = false;

	long long ans = 0;
	long long n = ((b - a) / c) + 1;
	ans += n*a;
	ans += n*(n-1) / 2 * c;

	if (out) {
		for (int i = a; i <=b; i+=c) {
		cout << i;
		if (i < b)
			cout << '+';
		}
		cout << '=';
	}
	cout << ans << endl;
}

long long factorial(int x) {
	long long result = 1;
	for (int i = 2; i <= x; ++i) {
		result *= i;
	}
	return result;
}

void f3() {
	cout << "Type m,n to get C(m,n):";
	int m, n;
	cin >> m >> n;

	long long a = factorial(m), b = factorial(n), c = factorial(m - n);
	long long ans = a / (b * c);
	cout << "C(" << m << ',' << n << ")=" << ans << endl;
}

int main() {

	double d = 114514.114514;
	cout.precision(3);
	cout << fixed << d;

	initTable();



	while (true) {
		cout << "type options:" << endl
		     << "1: judge if a number is prime" << endl
		     << "2: get sum of the array" << endl
		     << "3: permulation calculation" << endl
		     << "Your choice:";

		int c;
		cin >> c;
		switch (c) {
		case 1: {
			f1();
			break;
		}
		case 2: {
			f2();
			break;
		}
		case 3: {
			f3();
			break;
		}
		default: {
			cout << "wrong option!";
			break;
		}
		}
	}

	return 0;
}
