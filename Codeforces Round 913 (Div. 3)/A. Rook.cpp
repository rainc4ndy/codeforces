#include <bits/stdc++.h> 
  
#define mod (100)
#define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t; 

	char c;
	int n1[mod], n2[mod];
	
	for (int t1 = 0; t1 < t; t1++) {
		cin >> c >> n2[t1];
		n1[t1] = static_cast<int>(c - 'a') + 1;
	}

	for (int t1 = 0; t1 < t; t1++) {
		bool has = false;

		for (int i = 1; i <= 8; i++) {
			//column
			for (int k = 1; k <= 8; k++) {
				if (k == n1[t1] && i == n2[t1]) {
					continue;
				}
				if (k == n1[t1] || i == n2[t1]) {
					if (has)
						cout << endl;
					has = true;
					cout << (char)(k - 1 + 'a') << i;
				}
			}
		}
		if (t1 != t - 1)
			cout << endl;
	}

	return 0;
}