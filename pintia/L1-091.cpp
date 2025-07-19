#include <bits/stdc++.h> 
 
using namespace std;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n, m, k;
	string x;
	cin >> n >> x >> m >> k;

	if (k == n) {
		cout << "mei you mai " << x << " de";
	} else if (k == m) {
		cout << "kan dao le mai " << x << " de";
	} else {
		cout << "wang le zhao mai " << x << " de";
	}

	return 0;
}