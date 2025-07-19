#include <bits/stdc++.h>
using namespace std;

const int SZ = 8;
int v[SZ];
void f() {
	for (auto it : v) {
		cout << it << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	for (unsigned i = 0; i < SZ; ++i)
		v[i] = i + 1;
	f();

	int tmp[SZ];
	for(unsigned i = 0; i < SZ; i++)
		tmp[(i + k) % SZ] = v[i];
	memcpy(v, tmp, sizeof(v));
	f();

	return 0;
}
