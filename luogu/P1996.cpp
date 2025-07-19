#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n,m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) 
		v[i] = i+1;

	int i = 0;
	while (!v.empty()) {
		i += m-1;
		i %= v.size();
		cout << v[i];
		v.erase(v.begin() + i);
		if (!v.empty())
			cout << ' ';
	}

	return 0;
}