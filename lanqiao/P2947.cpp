#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;

int v[mod] {};
int d[mod] {};
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n;
    cin >> n;

    stack<int> st;

    for (int i = 1; i <= n;i++) {
    	cin >> v[i];

    	while (!st.empty()) {
    		if (v[st.top()] < v[i]) {
    			d[st.top()] = i;
    			st.pop();
    		} else {
    			break;
    		}
    	}
    	st.push(i);
    }

    for (int i = 1; i <= n; i++) {
    	cout << d[i] << endl;
    }
	return 0;
}