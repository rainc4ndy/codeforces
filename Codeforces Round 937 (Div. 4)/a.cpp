#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long 

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;
	vector<int> ans(t);
	int x,y,z;
	for (int i = 0; i < t; i++) {
		cin >> x >> y >> z;
		if (x < y && y < z)
			ans[i] = 0;
		else if (y > x && y > z)
			ans[i] = 2;
		else ans[i] = 1;
	}    

	for (int i = 0; i <t ; i++) {
		if (ans[i] == 0)
			cout << "STAIR";
		else if(ans[i] == 1)
			cout << "NONE";
		else cout << "PEAK";

		if (i != t-1)
			cout << endl;
	}

	return 0;
}