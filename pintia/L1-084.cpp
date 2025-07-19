#include <bits/stdc++.h> 
 
using namespace std;

int f(int n) {
	if (n == 1)
		return 1;
	return n * f(n - 1);
}

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
    int a, b;
    cin >> a >> b;

    cout << f(a + b);
	return 0;
}