#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n;
    cin >> n;

  	std::vector<int> v(n+1), sum(n+1);

    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
    	sum[i] = sum[i-1] + v[i]; 
    }

    int m;
    cin >> m;

   	vector<int> ans(m);

   	int x, y;
   	for (int i = 0; i < m; i++) {
   		cin >> x >> y;
 	  	ans[i] = sum[y] - sum[x-1];
   	}

   	for (int i = 0; i < m; i++) {
   		cout << ans[i];
   		if (i != m-1)
   			cout << endl;
   	}

	return 0;
}