#include <bits/stdc++.h> 
  
#define mod (100001)
#define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	int n, m;

	int count = 0;
	int ans[mod] {};

	string s1, s2;
	for (int i = 0; i < t; i++) {
		count = 0;
		cin >> n >> m;

		cin >> s1 >> s2;

		while (s1.find(s2) == string::npos) {
			s1.append(s1);
			count++;
			if (count >= n * m) {
				count = -1;
				break;
			}
		}

		ans[i] = count;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}