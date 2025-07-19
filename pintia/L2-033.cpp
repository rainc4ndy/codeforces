#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    stack<int> stk;
    stack<char> op;

	int n, x;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		stk.push(x);
	}

	char c;
	for (int i = 0; i < n-1; i++) {
		cin >> c;
		op.push(c);
	}

	int a, b, r;
	while(op.size()) {
		a = stk.top();
		if (!stk.empty())
			stk.pop();

		b = stk.top();
		if (!stk.empty())
			stk.pop();

		c = op.top();
		if (!op.empty())
			op.pop();

		switch (c) {
			case '+': {
				r = b + a;
				break;
			}
			case '*': {
				r = b * a;
				break;
			}
			case '/': {
				if (!a) {
					cout << "ERROR: " << b << "/0";
					return 0;
				}
				r = b / a;
				break;
			}
			case '-': {
				r = b - a;
				break;
			}
		}

		stk.push(r);
	}

	cout << stk.top() << endl;

	return 0;
}