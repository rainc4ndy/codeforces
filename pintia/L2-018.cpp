#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> e1(n), c1(n), e2(n), c2(n);
	for(unsigned i = 0; i <n; ++i) {
		cin >> e1[i] >> c1[i];
	}
	for(unsigned i = 0; i < n; ++i) {
		cin >> e2[i] >> c2[i];
	}



	return 0;
}
