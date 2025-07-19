#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int ans[mod] {};
int v[mod];
bool vis[mod] {};
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 


	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		//loc[v[i]] = i;
	}

	int ptr = 0;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;

		if (vis[tmp]) {
			ans[i] = 0;
			continue;
		}

		for (int j = ptr; j < n; j++) {
			vis[v[j]] = true;
			if (v[j] == tmp) {
				ans[i] = j-ptr+1;
				ptr = j+1;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}