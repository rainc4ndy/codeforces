#include <bits/stdc++.h> 
#include <cmath>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int h, c, p;
    cin >> h >> c >> p;
    for (int i = 1; i <= 10; i++) {
    	float t = (float)h/i;
    	float w = -p*t+c;
    	if (w >= 0) {	
    		cout << i;
    		return 0;
    	}
    }
    cout << -1;

	return 0;
}