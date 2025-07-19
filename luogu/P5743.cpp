#include <bits/stdc++.h> 
 
int main() {

	using namespace std;
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n;
    cin >> n;

    int d = 1, a = 1;
    while (d != n) {
    	a += 1;
    	a *= 2;
    	d++;
    }

    cout << a;

	return 0;
}