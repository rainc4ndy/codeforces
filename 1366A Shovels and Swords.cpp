#include <bits/stdc++.h> 
#include <cwchar>
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	int stick[1001] {}, diamond[1001] {};
	for (int i = 0; i <= n; i++) {
		cin >> stick[i] >> diamond[i];
	}

	for (int i = 0; i <= n; i++) {
		int earn = 0;
		while (stick[i] >= 2 && diamond[i] >= 1) {
			if (stick[i] > diamond[i]) {
				stick[i] -= 2;
				diamond[i] -= 1;
			} else {
				diamond[i] -= 2;
				stick[i] -= 1;
			}
			earn++;
		}
		cout << earn;
		if (i != n - 1)
			cout << endl;
	}

	return 0;
}