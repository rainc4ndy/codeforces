#include <bits/stdc++.h> 
 
using namespace std;

long long f(long long integer) {
	int tmp = 0;
	while (integer != 0) {
		tmp += integer % 10;
		integer /= 10; 
	}
	return tmp;
}

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    vector<bool> ans;

    int n;
	long long a, b, sa, sb;
	bool fa, fb;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		sa = f(a);
		sb = f(b);

		fa = ((double)a / (double)sb) - (a / sb) == 0;
		fb = ((double)b / (double)sa) - (b / sa) == 0;

		if (fa == fb)
			ans.push_back(b > a);
		else 
			ans.push_back(fb);
	}

	for (int i = 0; i < n; i++) {
		cout << (ans[i] ? "B" : "A");
		if (i != n -1) 
			cout << endl;
	}

	return 0;
}