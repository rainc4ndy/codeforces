#include <bits/stdc++.h> 

#define mod (100001)
#define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	ll n;
	cin >> n;
	if (n % 2 == 0) {
		cout << (n / 2);
	} else {
		cout << ((n / 2) + 1) * (-1);
	}

	return 0;
}