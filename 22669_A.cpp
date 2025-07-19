#include <bits/stdc++.h>


using namespace std;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int mx = 0;
	int tmp;

	cin >> n;

	stack<int> st;
	vector<int> in;
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		in.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mx = max(in[j], mx);
		}
		
		//cout << "mx = " << mx << "    st.top() = " << st.top() << endl;
		while (!st.empty() && st.top() >= mx) {
			ans.push_back(st.top());
			st.pop();
			cout << "pop " << in[i] << endl;
		}
		st.push(in[i]);
		cout << "push " << in[i] << endl;
		
		if (in[i] == mx) {
			mx = 0;
			in[i] = 0;
		}
	}

	// clear up
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i != n - 1 )
			cout << ' ';
	}

	return 0;
}