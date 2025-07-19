#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int q;
    cin >> q;

    string s;
    cin >> s;

    vector<string> ans(q);

    int r;
    for (int i = 0; i <q; i++) {
    	cin >> r;
    	if (r == 1) {
    		string tmp;
    		cin >> tmp;
    		s.append(tmp);
    		ans[i].append(s);
    	} else if (r == 2) {
    		int x, y;
    		cin >> x >> y;
    		ans[i] = s = s.substr(x, y);
    	} else if (r == 3) {
    		int x; string tmp;
    		cin >> x >> tmp;

    		s.insert(x, tmp);
    		ans[i] = s;
    	} else if (r == 4) {
    		string tmp;
    		cin >> tmp;
    		int pos = s.find(tmp);
    		ans[i] = to_string((pos == string::npos ? -1 : pos));
       	}
    }

    for (int i = 0; i < q; i++) {
    	cout << ans[i];
    	if (i != q-1)
    		cout << endl;
    }
	return 0;
}