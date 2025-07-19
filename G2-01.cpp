#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

vector<bool> prime(mod, true);

void solve() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= mod; i++) {
		if (prime[i]) {
			for (int j = i * i; i <= mod; j += i) {
				prime[i] = false;
			}
		}
	}

	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}