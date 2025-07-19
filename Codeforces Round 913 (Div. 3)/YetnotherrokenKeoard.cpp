#include <bits/stdc++.h> 
#include <cctype>
#include <cstring>
#include <stack>

#define mod (100001)
#define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

  	int t;
  	cin >> t;

  	vector<string> ans;
  	string s;
  	char data[mod] {};
  	int l = 0;
  	
  	for (int i = 0; i < t; i++) {
  		cin >> s;

  		l = s.length();
  		memset(data, 0, sizeof(char) * l);
  		stack<int> last_upper;
  		stack<int> last_lower;
  		
  		for (int k = 0; k < l; k++) {
  			if (s[k] == 'b') {
  				s[k] = '$';
  				if (last_lower.size() > 0) {
  					s[last_lower.top()] = '$';
  					last_lower.pop();
  				}
  			} else if (s[k] == 'B') {
  				s[k] = '$';
  				if (last_upper.size() > 0) {
  					s[last_upper.top()] = '$';
  					last_upper.pop();
  				}
  			} else {
  				if (isupper(s[k])) {
	  				last_upper.push(k);
	  			} else if (islower(s[k])) {
	  				last_lower.push(k);
	  			}
  			}	
  		}
  		ans.push_back(s);
  	}

  	for (int i = 0; i < t; i++) {
  		for (int j = 0; j < ans[i].length(); j++) {
  			if (ans[i][j] != '$')
  				cout << ans[i][j];
  		}
  		if (i != t - 1)
  			cout << endl;
  	}

	return 0;
}