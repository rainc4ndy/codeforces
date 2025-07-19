#include <bits/stdc++.h> 
#include <vector> 
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n, t;
	cin >> n;

	float s = n;
	float sum = 0;
	while(n--) {
		cin >> t;
		sum += static_cast<float>(t) / 100.f;		
	}

	cout << (sum / s) * 100.f;

	return 0;
}