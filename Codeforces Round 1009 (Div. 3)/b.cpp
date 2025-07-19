#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > pq;
	ll num = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push(num);
	}

	if (n == 1) {
		cout << pq.top() << endl;
		return;
	}

	while (pq.size() > 1) {
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();
		pq.push(a + b - 1);
	}
	cout << pq.top() << endl;
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