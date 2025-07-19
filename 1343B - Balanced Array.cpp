#include <bits/stdc++.h> 
#include <vector>
  
#define mod (100001)
#define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 


	int n;
	cin >> n;

	vector<vector<int>> ans;
	vector<bool> bns;
	
	int tmp = 0, sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;

		sum1 = sum2 = 0;
		ans.emplace_back(vector<int>());
		for (int j = 1; j <= tmp; j++) {
			if (j % 2 == 0) {
				sum1 += j;
				ans[i].push_back(j);
			}
		}
		for (int j = 1; j <= tmp; j++) {
			if (j % 2 != 0) {
				sum2 += j;
				ans[i].push_back(j);
			}
		}
		printf("sum1 = %d, sum2 = %d\n", sum1, sum2);
		bns.push_back(sum1 == sum2);
	}

	for (int i = 0; i < n; i++) {
		if (bns[i]) {
			cout << "YES" << endl;
		}
		cout << "NO";
		if (i != n - 1) {
			cout << endl;
		}
	}

	return 0;
}