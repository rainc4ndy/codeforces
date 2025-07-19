#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, pe;
    cin >> n;
    unordered_map<int, int> m;

    for(unsigned i = 0; i < n; ++i) {
    	cin >> a;
    	for(unsigned j = 0; j < a; ++j) {
    		cin >> pe;
    		if (a == 1 && !m[pe])
    			continue;
    		m[pe]++;
    	}
    }

    set<int> exist;
    vector<int> ans;

    cin >> a;
    int b;

    for(unsigned i = 0; i < a; ++i) {
    	cin >> b;
    	if (m[b] < 1) {
    		if (exist.count(b) == 0) {
    			ans.push_back(b);
    			exist.insert(b);
    		}
    	}
   	}

   	if (ans.empty()) {
   		cout << "No one is handsome";
   		return 0;
   	}

   	for (int i =0; i < ans.size(); i++)  {
   		cout << setfill('0') << setw(5) << ans[i];
   		if (i != ans.size() - 1)
   			cout << ' ';
   	}

	return 0;
}
