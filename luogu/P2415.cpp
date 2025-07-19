#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    vector<int >v;

    long long n;
	while (cin.peek() != '\n') {
		cin >> n;
		v.push_back(n);
	} 
	long long ans = 0;
	long long f = pow(2, v.size() - 1);
	for (auto it : v)
		ans += it * f;

	cout << ans;
	return 0;
}