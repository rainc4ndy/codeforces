#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k; //m: chest, k: mx on twig
	cin >> n >> m >> k;

	int x, y;
	deque<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	vector<vector<int>> ans;
	int cnt = 0;

	stack<int> box;
	stack<int> twig;
	while (!v.empty()) {
		if (twig.empty()) {
			if (!box.empty()) {
				x = box.top();
				box.pop();
			} else if (!v.empty()) {
				x = v.front();
				v.pop_front();
			}
			twig.push(x);
		} else {
			if (box.top() > twig.top()) {
				if (v.empty()) {
					ans.emplace_back(vector<int>());
					while (!twig.empty()) {
						ans[cnt].push_back(twig.top());
						twig.pop();
					}
					cnt++;
					continue;
				}
				if (v.front() > twig.top()) {
					box.push(v.front());
					v.pop_front();

					if (box.size() >= m) {
						ans.emplace_back(vector<int>());
						while (!twig.empty()) {
							ans[cnt].push_back(twig.top());
							twig.pop();
						}
						cnt++;
						continue;
					}
				} else {
					twig.push(v.front());
					v.pop_front();
				}
			} else {
				twig.push(box.top());
				box.pop();
			}
		}
		if (twig.size() >= k) {
			ans.emplace_back(vector<int>());
			while (!twig.empty()) {
				ans[cnt].push_back(twig.top());
				twig.pop();
			}
			cnt++;
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j];
			if (j != ans[i].size() - 1)
				cout << ' ';
		}
		if (i != ans.size())
			cout << endl;
	}

	return 0;
}
