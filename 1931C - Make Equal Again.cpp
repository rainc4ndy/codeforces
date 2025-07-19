#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;

	cin >> t;
	int v[200001];
	int ans[10001];

	int s, e, ptr1, ptr2;
	bool f1, f2;

	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> v[j];

		if (n == 1) {
			ans[i] = 0;
			continue;
		}

		ptr1 = 0;
		ptr2 = n - 1;

		s = v[ptr1];
		e = v[ptr2];
		f1 = f2 = true;

		while (f1 || f2) {
			if (v[ptr1] == s && ptr1 != n - 1)
				ptr1++;
			else 
				f1 = false;

			if (v[ptr2] == e && ptr2 != 0) 
				ptr2--;
			else
				f2 = false;
		}

		ans[i] = s == e ? max(0, ptr2 - ptr1 + 1) : n - max(ptr1, n - ptr2 - 1);
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}
	return 0;
}