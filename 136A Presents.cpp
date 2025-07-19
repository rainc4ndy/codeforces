#include <bits/stdc++.h> 
#include <random>

#define mod (100001)
#define ll long long
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	int g[mod] {};

	for (int i = 0 ; i < n; i++) {
		cin >> g[i];
	}

	for (int i = 0; i < n; i++) {
		cout << g[g[g[i] - 1] - 1];
		if (i != n -1)
			cout << " ";
	}

	return 0;
}