#include <bits/stdc++.h>
using namespace std;

const int SZ = 32;
int a[SZ] {};

void dirt() {
	for (auto it : a)
		cout << it << ' ';
	cout << endl;
}

// 时间复杂度: O(n);
void my_corpse() {
	int r = 0, t = SZ - 1;
	while (r < t) {
		while(a[r] < 0) r++;
		while(a[t] >= 0) t--;
		swap(a[r], a[t]);
	}
}

int main() {
	for (unsigned i = 0; i < SZ; ++i)
		a[i] = i % 3 == 0 ? -i : i;

	dirt();
	my_corpse();
	dirt();
	return 0;
}
