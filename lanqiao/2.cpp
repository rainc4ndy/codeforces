#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    cin >> m >>d;
    if (m <= 0 || m > 12) {
    	cout << "no";
    	return 0;
    }
    if (d <= 0 || d > v[m-1]) {
    	cout << "no";
    	return 0;
    }
    cout << "yes";

	return 0;
}
