#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int multiplier[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	char id[] = "10X98765432";

	vector<string> ans;
	string tmp;
	int z;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		z = 0;
		for (int i = 0; i < 17; i++) {
			z += (tmp[i] - '0') * multiplier[i];
		}
		z %= 11;
		if (id[z] != tmp[17])
			ans.push_back(tmp);
	}

	if (ans.size() == 0) {
		cout << "All passed";
		return 0;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << endl;
	}

	return 0;
}