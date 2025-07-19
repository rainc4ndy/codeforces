#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int h1, m1, s1, h2, m2, s2;
	char c;
	cin >> h1 >> c
	    >> m1 >> c
	    >> s1;

	cin >> h2 >> c
	    >> m2 >> c
	    >> s2;

	int n;
	cin >> n;

	long long sum = 0;
	h2 -= h1;
	m2 -= m1;
	s2 -= s1;

	sum += m2*60 + h2*3600 + s2;
	cout << n*sum;

	return 0;
}