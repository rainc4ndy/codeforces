#include <bits/stdc++.h> 
#include <vector>
 
using namespace std;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n; 
	int tmp;
	vector<int> cap;

	cin >> n;

	for (int i = 0 ; i < n ; i++) {
		cin >> tmp;
		cap.push_back(tmp);
	}

	int k;
	int wa, ac;

	cin >> k;

	vector<bool> ans;

	for (int i = 0; i < k; i++) {
		wa = 0;
		ac = 0;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == 0)
				continue;
			if (tmp == cap[j])
				ac++;
			else
				wa++;
		}
		ans.push_back(wa == 0 && ac >= 1);
	}

	for (int i = 0; i < k; i++) {
		if (ans[i]) {
			cout << "Da Jiang!!!";
		} else {
			cout << "Ai Ya";
		}
		if (i != k-1) {
			cout << endl;
		}
	}

	return 0;
}