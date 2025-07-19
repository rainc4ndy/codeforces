#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool f(int n) {
	string s = to_string(n);
	for (auto it : s) {
		if (it != '0' && it != '1')
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	vector<int> ans(t);
	int n;
	int k = 2;
	int interpretedAsDec = 0;
	int pre = -1;
	string binaryStr;

	for (int i = 0; i < t; i++) {
		cin >> n;
		if (f(n)) {
			ans[i] = true;
			continue;
		}

		k = 2;
		interpretedAsDec = 0;
		pre = -1;


		while (n > 1 && k < 80) {
			if (pre != k) {
				binaryStr = std::bitset<32>(k).to_string(); // to binary
				binaryStr.erase(0, binaryStr.find_first_not_of('0'));

				interpretedAsDec = 0;
				for (char digit : binaryStr) {
					interpretedAsDec = interpretedAsDec * 10 + (digit - '0');
				}
			}

			if (n % interpretedAsDec == 0) {
				n /= interpretedAsDec;
				pre = k;
			} else {
				k++;
			}
		}
		ans[i] = n <= 1;
	}

	for (int i = 0; i < t; i++) {
		cout << (ans[i] ? "YES" : "NO");
		if (i != t - 1)
			cout << endl;
	}
	return 0;
}
