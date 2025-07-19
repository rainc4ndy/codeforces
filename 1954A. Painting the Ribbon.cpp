#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t; 

	int n,m,k;
	vector<bool> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k;

		int b = n / m; 
		int r = n - m * b;
		int paint = (m-1) * b;
		if (r)
			paint += r-1;
		//cout << "paint = " << paint << endl;
		ans[i] = k < paint;
	}

	for (int i = 0; i <t; i++) {
		if (ans[i])
			cout << "YES";
		else cout << "NO";
		if (i != t-1)
			cout << endl;
	}
	return 0;
}