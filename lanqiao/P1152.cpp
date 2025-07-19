#include <bits/stdc++.h>
#include <memory>
#include <vector>
using namespace std;

const int mod = 1e6 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	ll v[2000], d[2000];


	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		d[i] = abs(v[i] - v[i + 1]);
	}
	sort(d + 1, d + n);

	for (int i = 1; i < n; i++) {
		if (d[i] != i) {
			cout << "Not jolly";
			return 0;
		}

	}
	cout << "Jolly";

	return 0;
}