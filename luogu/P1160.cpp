#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int loc[mod] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	int k,p;
	int y;

	vector<int> v;
	v.push_back(1);
	loc[1] = 1;

	for (int i = 0; i < n-1; i++) {
		cin >> k >> p;
		y = i+2;
		if (p == 0) {
			v.insert(v.begin()+loc[k], y);
		} else {
			v.insert(v.begin()+loc[k]+1, y);
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> y;
	}

	return 0;
}