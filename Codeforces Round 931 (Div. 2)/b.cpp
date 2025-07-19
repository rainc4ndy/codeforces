#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define SZ 5
int vs[SZ] = {1, 3, 6, 10, 15};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	int n;
	vector<int > ans(t);
	for(unsigned i = 0; i < t; ++i) {
		cin >> n;

		for(unsigned j = SZ - 1; j >= 0; j--) {
			while (n != 0) {
				if (n % vs[j] == 0) {

				}
				ans[i] += n;
			}
		}
	}

	return 0;
}
