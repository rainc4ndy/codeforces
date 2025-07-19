#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t,n;
	cin >> t;

	vector<int> ans(t);
	int v[51] {};

	int l, r;

	for (int i = 0; i <t; i++) {
		cin >> n;

		for (int j=0; j <n; j++) {
			cin >> v[j];
		}


		for (int j=0; j <n; j++) {
			if (v[j] == 1){
				l = j;
				break;
			}
		}
		for (int j=n-1; j >= 0; j--) {
			if (v[j] == 1){
				r = j;
				break;
			}
		}


		for (int j=l; j <= r; j++) {
			if (!v[j])
				ans[i]++;
		}
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t-1)
			cout << endl;
	}

	return 0;
}