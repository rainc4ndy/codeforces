#include <bits/stdc++.h> 
#include <ostream>
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    for (int i=1, e=i; i<=2000; i++, e=i) {
    	if (i&1)
    		continue;
    	
    	int p = 2000;
    	bool b = true;
    	while (p > 2) {
    		p /= 2;
    		p++;
    		e /= 2;

    		if (e == 1)
    			break;
    		if (e&1) {
    			b = false;
    			break;
    		}
    	}
    	if (p == 3 && b) {
    		cout << i << endl;
    	}
    }
	return 0;
}