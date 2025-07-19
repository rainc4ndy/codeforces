#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,d;
	cin >> n >> d;

	cout << "1 ";
	if (d == 1) {
		if (n == 1) {
		}
		else if (n > 2) {
			cout << "3 7 9";
		}
	} else if (d == 2) {
		if (n <= 2) {
			cout << "1";
		}
		else {
			cout << "3 7";
		}
	}
	else if (d == 3) {
		if (n == 1) {
		}
		else if (n == 2) {
			cout << "3";
		}
		else {
			cout << "3 7 9";
		}
	}
	else if (d == 4) {
		if (n == 1) {
		}
		else if (n == 2) {
		}
		else {
			cout << "3 7";
		}
	}
	else if (d == 5) {
		if (n == 1) {
		}
		else if (n == 2) {
			cout << "5";
		}
		else if (n == 3) {
			cout << "3 5 7";
		}
		else {
			cout << "3 5 7 9";
		}
	}
	else if (d == 6) {
		if (n == 1) {
			cout << "3";
		}
		else if (n == 2) {
			cout << "3";
		}
		else {
			cout << "3 7 9";
		}
	}
	else if (d == 7) {
		if (n == 1) {
			cout << "3";
		}
		else {
			cout << "3 7";
		}
	}
	else if (d == 8) {
		if (n == 1) {
			cout << "3";
		}
		else {
			cout << "3 7";
		}
	}
	else if (d == 9) {
		if (n == 1) {
			cout << "3";
		}
		else if (n == 2) {
			cout << "3";
		}
		else {
			cout << "3 7 9";
		}
	}

	cout << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}