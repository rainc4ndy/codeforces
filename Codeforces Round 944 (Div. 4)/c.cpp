#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

bool f(int a, int b, int c, int d) {
    if (a > b) swap(a, b);  
    if (c > d) swap(c, d);

    return ((a < c && c < b && !(a < d && d < b)) || (a < d && d < b && !(a < c && c < b)) ||
            (c < a && a < d && !(c < b && b < d)) || (c < b && b < d && !(c < a && a < d)));
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	vector<bool> ans(t);

	int a,b,c,d;

	for (int i = 0; i <t ; i++) {
		cin >> a >> b >> c >> d;
		ans[i] = f(a,b,c,d);
	}
	for (int i = 0; i < t; i++){
		if (ans[i])
			cout << "YES";
		else cout << "NO";

		if (i!=t-1)
			cout << endl;
	}

	return 0;
}