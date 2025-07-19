#include <bits/stdc++.h> 
using namespace std;


int f(const string& s) {
    int tr = 1;
    int n = s.length();
    
    for (int i = 1; i < n; ++i) {
        if (s[i-1] == '1' && s[i] == '0') {
            tr++;
        }
    }

    return tr;
}

int main() {
	
    int t;
    cin >> t;
    vector<string> cases(t);

    for (int i = 0; i < t; ++i) {
        cin >> cases[i];
    }

    for (int i = 0; i < t; ++i) {
        cout << f(cases[i]);
        if (i != t-1)
        	cout << endl;
    }

    return 0;
}
