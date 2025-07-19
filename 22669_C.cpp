#include <bits/stdc++.h> 
#include <queue>
  
#define mod (100001)
#define ll long long

// NC21874

struct e {
	char v;
	int k;
};

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    string s;
    cin >> s;

    // must be % 2
    int l = s.length();
    if (l % 2 != 0) {
    	cout << "Bad";
    	return 0;
    }

   	// stacks
    queue<e> qa, qb;
    e tmp;

    for (int i = 0; i < l; i++) {
    	tmp.v = s[i];
    	tmp.k = i;
    	if (tmp.v == 'a')
    		qa.push(tmp);
    	else qb.push(tmp);
    }

    // size check
    if (qa.size() != qb.size()) {
    	cout << "Bad";
    	return 0;
    }

    //ia's always lesser than lb
    while (qa.size() != 0) {
    	if (qa.front().k > qb.front().k) {
    		cout << "Bad";
    		return 0;
    	}
    	qa.pop();
    	qb.pop();
    }


    cout << "Good";
	return 0;
}