#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n,x;
    cin >> n >>x;

	for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            for (int c = 1; c <= 100; c++) {
            	if (a*b+a*c+b*c<=n && a+b+c<=x) {
            		cout << "(a,b,c) = " << a << ' ' << b << ' ' << c << endl;
            	}
            }
        }
    }

	return 0;
}