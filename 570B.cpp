#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n,m;
	cin >> n >> m;

	ll med = ceil((double)n/(double)2);
	int a;

	if (n == 2) {
		a = n-m+1;
	} else if (n == 1) {
		a = 1;
	} else {
		if (n % 2 != 0) {
			if (m == med) {
				a = m-1;
			}
			else if (m > med) {
				a = m-1;
			} else {
				a = m+1;
			}		
		} else {
			if (m == med) {
				a = m+1;
			}
			else if (m > med) {
				a = m-1;
			} else {
				a = m+1;
			}		
		}
	}

	cout << a;
	return 0;
}