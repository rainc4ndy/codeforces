#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, n2;
    int p;
    int v[10001] {}, v2[10001] {};
    cin >> n;
   	for(int i = 0; i < n; ++i) {
   		cin >> k;
   		for(int j = 0; j < k; ++j) {
   			cin >> n2 >> p;
   			v[n2-1] += p;
   			v[i] -= p;
   			v2[n2-1]++;
   		}
   	}

   	int mx = 0, mxi = 0;
   	for(int i = 0; i < n; ++i) {
   		mx = -INF;
   		for(int j = 0; j < n; ++j) {
   			if (v[j] > mx) {
   				mx = v[j];
   				mxi = j;
   			} else if (v[j] == mx) {
   				if (v2[j] > v2[mxi]) {
   					mx = v[j];
   					mxi = j;
   				} else if (v2[j] == v2[mxi]) {
   					if (j < mxi) {
   						mx = v[j];
   						mxi = j;
   					}
   				}
   			}
   		}
   		cout << mxi+1 << ' ' << setprecision(2) << fixed << mx/100.f;
   		v[mxi] = -INF; //标记移除
   		if (i != n-1)
   			cout << endl;
	}


	return 0;
}
