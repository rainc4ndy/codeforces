#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long


vector<int> u[mod];
int cost[mod] {};

vector<int> v;
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int m,n;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++) {
    	cin >> x >> y >> cost[i];
    	u[x].push_back(y); 
    	u[y].push_back(x); 
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
    	v.clear();

    	cin >> x;
    }
	return 0;
}