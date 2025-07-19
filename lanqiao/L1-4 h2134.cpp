#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    string n; int k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
    	int mx = 0;
    	int mxi = 0;
    	for (int y = 0; y < n.size(); y++) {
    		if (n[y] != '$') {
    			if (n[y] > mx) {
    				mx = n[y];
    				mxi = y;
    			}
    		}
    	}
    	n[mxi] = '$';
    }
    for (int y = 0; y < n.size(); y++) {
    	if (n[y] != '$') {
    		cout << n[y];
    	}
    }
	
	return 0;
}