#include <bits/stdc++.h> 
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	int k = 0;
	int Max = 0, Min = 100000;
	int ans = 0;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> k;
		if (i == 0) {
			Max = Min = k;
			continue;
		}
		if (k > Max) {
			Max = k;
			//cout << "Max = " << Max << endl;
			ans++;
		}
		else if (k < Min) {
			Min = k;
			//cout << "Min = " << Min << endl;
			ans++;
		}
	}
	cout << ans;

	return 0;
}