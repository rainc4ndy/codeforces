#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int graph[1001][1001];
int n;

void solve() {
	cin >> n;
	char c;
	for (int i =0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin >> c;
			graph[i][j] = c-'0';
		}
	}
	
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