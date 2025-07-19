#include <bits/stdc++.h> 
#include <iomanip>
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	int x,y;
	char c;

	vector<pair<int, int>> ans(t);
	vector<bool> d(t);

	for (int i = 0; i < t; i++) {
		cin >> x >> c >>  y;

		if (x >= 13) {
			x -= 12;
			d[i] = true;
		} else {
			if (x == 0) {
				x += 12;
				d[i] = false;
			} else if (x == 12) {
				d[i] = true;
			} else 
			d[i] = false;
		}
		ans[i] = {x, y};
	}


	for (int i = 0; i < t; i++) {

		cout << setw(2) << setfill('0') << ans[i].first;
		cout << ':';
		cout << setw(2) << setfill('0') << ans[i].second;
		cout << ' ' << (d[i] ? "PM" : "AM");

		if (i != t-1)
			cout << endl;
	}

	return 0;
}