#include <bits/stdc++.h> 
#include <deque>
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n, k;
	cin >> n >> k;

	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	deque<int> q, qm;

	vector<int> ans_mi, ans_mx;

	for (int i = 1; i <= n; i++) {
		// 维护队列的单调性，如果新进来的元素更小，那么循环弹出队尾
		while (!q.empty() && v[q.back()] >= v[i]) {
			q.pop_back();
		}
 
 		// 同上，如果新的元素进来更小
 		while (!qm.empty() && v[qm.back()] <= v[i]) {
			qm.pop_back();
 		}

		q.push_back(i);
		qm.push_back(i);

		while(i-k >= q.front())  //T掉不在范围内的
        	q.pop_front();

        while(i-k >= qm.front())
        	qm.pop_front();

        if (i >= k) {
        	ans_mi.push_back(v[q.front()]);
        	ans_mx.push_back(v[qm.front()]);
        }
	}

	for (int i = 0; i < ans_mi.size(); i++) {
		cout << ans_mi[i];
		if (i != ans_mi.size() -1)
			cout << ' ';
	}
	cout << endl;

	for (int i = 0; i < ans_mx.size(); i++) {
		cout << ans_mx[i];
		if (i != ans_mx.size() - 1)
			cout << ' ';
	}
	return 0; 
}