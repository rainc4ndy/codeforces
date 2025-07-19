#include <algorithm>
#include <bits/stdc++.h> 

#define mod (100001)
#define ll long long

//start point, endpoiot
ll a[mod] {}, b[mod] {};

//divide and conquer
int solve(int size, int index) {
	int m = 0;

	ll rear = a[index], front = b[index]; 

	for (int i = 0; i < size; i++) {
		//check overlapped ones (fully)
		//check fully overlapped number line 
		//cuz people moving simultaneously at a speed of 1
		if ((rear >= a[i] && front <= b[i]) || (a[i] >= rear && b[i] <= front)) {
			m++;
		}
	}

	return m;
}

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;

	cin >> t;

	int n;
	int ans[10001] {};

	for (int i = 0; i < t; i++) {
		cin >> n;

		// n people
		for (int t = 0; t < n; t++) {
			cin >> a[t] >> b[t];

			ans[i] += solve(t, t);
		}
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];

		if (i != t - 1) 
			cout << endl;
	}

	return 0;
}