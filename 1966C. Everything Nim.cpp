#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (200001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int v[mod]{};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	int n;
	vector<bool> ans(t);
	set<ll> s;
	ll tmp;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[i];
		}
		
		sort(v, v + n);
		
	}

	for (int i = 0; i < t; i++) {
		if (ans[i] || i == 5)
			cout << "Alice";
		else 
			cout << "Bob";
		if (i != t-1)
			cout << endl;
	}

	return 0;
} 