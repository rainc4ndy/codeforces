#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>  

#define mod (2048)

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	int qua[mod];

	int ans[mod];

	for (int i = 0; i < t; i++) {
		memset(qua, 0, sizeof(int) * mod);
		int n;
		cin >> n;
		int tmp;
		for (int j = 0; j < n; j++) {
			cin >> tmp >> qua[j];
			if (qua[j] >= 10)
				qua[j] = 0;
		}
		
		int max_v = qua[0], max_i = 0;
		for (int j = 0; j < n; j++) {
			if (max_v < qua[j]) {
				max_v = qua[j];
				max_i = j;
			}
		}

		ans[i] = max_i;
	}

	for (int i = 0; i < t; i++) {
		cout << "Case" << endl;
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}