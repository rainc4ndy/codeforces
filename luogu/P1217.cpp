#include <bits/stdc++.h>
#include <cmath>

using namespace std;

map<long long, bool> m;

bool prime(long long n) {
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i < std::sqrt(n); i += 2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void gen(long long a, long long b) {

	int l1 = to_string(a).length();
	int l2 = to_string(b).length();

	for (int i = l1; i < l2; ++i)
	{

	}
}

void gen_pa() {
	int d1, d2, d3, d4, d5;
	int r = 0;

	for (d1 = 1; d1 <= 9; d1 += 2) {
		m[d1] = true;
	}
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			r = 100 * d1 + 10 * d2 + 1 * d1;
			m[r] = true;
		}
	}
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			r = 1000 * d1 + 100 * d2 + 10 * d2 + d1;
			m[r] = true;
		}
	}
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				r = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
				m[r] = true;
			}
		}
	}
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				r = 100000 * d1 + 10000 * d2 + 1000 * d3 + 100 * d3 + 10 * d2 + d1;
				m[r] = true;
			}
		}
	}
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				for (d4 = 0; d4 <= 9; d4++) {
					r = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
					m[r] = true;
				}
			}
		}
	}
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				for (d4 = 0; d4 <= 9; d4++) {
					r = 10000000 * d1 + 1000000 * d2 + 100000 * d3 + 10000 * d4 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
					m[r] = true;
				}
			}
		}
	}
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				for (d4 = 0; d4 <= 9; d4++) {
					for (d5 = 0; d5 <= 9; d5++) {
						r = 100000000 * d1 + 10000000 * d2 + 1000000 * d3 + 100000 * d4 + 10000 * d5 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
						m[r] = true;
					}
				}
			}
		}
	}
}

int main() {

	gen_pa();

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;

	cin >> a >> b;

	for (auto it : m) {
		if (it.first >= a && it.first <= b) {
			if (prime(it.first)) {
				cout << it.first << endl; 
			}
		}
	}

	return 0;
}
