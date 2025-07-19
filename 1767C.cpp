#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[101][101] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n-i; j++) {
			cin >> v[i][j];
		}
	}

	return 0;
}