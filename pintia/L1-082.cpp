#include <bits/stdc++.h> 
 
using namespace std;

int main() {
    

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	long long n;
	int v;

	cin >> n >> v;

	cout << static_cast<int>( n /v ); 

	return 0;
}