#include <bits/stdc++.h> 
#include <functional>
#include <queue>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	priority_queue<int, vector<int>> pq;
	pq.emplace(1);
	pq.emplace(2);
	pq.emplace(3);
	cout << pq.top();
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
} 