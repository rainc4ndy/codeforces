#include <bits/stdc++.h>
using namespace std;

int v[10001];
int n;

void f(int x, int y)  {
	if (x >= n || y >= n)
		return;
	int r = v[x]*v[x+1];
	if (r > 9) {
		v[y+2] = r % 10;
		v[y+1] = r / 10;
		f(x+1, y+2);
	} else {
		v[y+1] = r;
		f(x+1, y+1);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> v[0] >> v[1] >> n;
	f(0, 1);

	for(unsigned i = 0; i < n; ++i) {
		cout << v[i];
		if (i != n -1)
			cout << ' ';
	}


	return 0;
}
