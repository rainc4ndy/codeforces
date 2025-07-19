#include <bits/stdc++.h> 
#include <random>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	char c1,c2;
	cin >> c1 >> c2;
	cin.ignore();

	cout << (c1-'0')+(c2-'0') << endl;

}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}