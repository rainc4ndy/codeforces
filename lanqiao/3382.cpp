#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n, m ;
	cin >> n >> m;

	vector<int> sum(n+1);

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum[i] = tmp + sum[i-1];
	}

	return 0;
}