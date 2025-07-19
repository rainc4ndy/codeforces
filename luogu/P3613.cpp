#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<ll, ll> P;

map<P, ll> um;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n,q;
    cin >> n >> q;
    int tmp;
    int x,y,z;

    vector<int> ans;
    for (int i = 0; i < q; i++) {
    	cin >> tmp;
    	if (tmp == 1) {
    		cin >> x >> y >> z;
    		um[{x,y}] = z;
    	} else {
    		cin >> x >> y;
    		ans.push_back(um[{x,y}]);
    	}	
    }

    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i];
    	if (i != ans.size()-1)
    		cout << endl;
    }

	return 0;
}