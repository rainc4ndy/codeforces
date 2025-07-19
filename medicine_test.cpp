#include <bits/stdc++.h> 

#define mod (100001)
#define ll long long

int da[mod] {}, db[mod] {};
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> da[i] >> db[i];
	}

	int dc[6] {}; //lianxu cons (max) 
	int mx = 0; //max of K (level)
	int tmp = 0; //chuxian

	for (int i = 1; i <= 5; i++) {
		tmp = 0;
		mx = 0;
		for (int k = 0; k < t; k++) {
			if (da[k] == i || db[k] == i) {
				tmp++;
			} 
			if ((da[k] != i && db[k] != i) || k == t - 1) {
				mx = max(tmp, mx);
				tmp = 0;
			}
		}
		dc[i] = mx;
	}

	int ans_l = 0, ans_k = 0;
	for (int i = 1; i <= 5; i++) {
		if (ans_l < dc[i]) {
			ans_l = dc[i];
			ans_k = i;
		}
	}

	cout << ans_l << ' ' << ans_k;

	return 0;
}