#include <bits/stdc++.h> 
#include <cmath>
using namespace std;


int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	long long x, n, k = 1;
	cin >> x >> n;
	for(unsigned i = 0; i < n; ++i) {
		k *= (x + 1);
	}
	cout << k;

	return 0;
}