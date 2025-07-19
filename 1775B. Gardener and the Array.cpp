#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t; 

	map<int, int> cnt; //竖着看，二进制1的个数
	vector<vector<int>> v; //对于数组中的每个数字，1出现的位置
	
	vector<bool> ans(t);
	int n, k, tmp;
	for (int i = 0; i < t; i++) {
		cin >> n;

		cnt.clear();
		v.clear();
		v.resize(n);

		for (int y= 0 ;y < n;y++) {
			cin >> k;
			for (int z = 0; z < k; z++) {
				cin >> tmp;
				cnt[tmp]++;
				v[y].push_back(tmp);
			}
		}

		bool ok = false;
		for (int y = 0; y < n; y++) {
			ok = true;
			for (int z = 0; z < v[y].size(); z++) {
				if (cnt[v[y][z]] == 1) { //往下找，统计的只有一个1，说明或运算结果不符合题意
					ok = false;
					break;
				}
			}
			if (ok)
				break;
		}
		ans[i] = ok;
	}

	for (int i = 0; i < t; i++) {
		if (ans[i])
			cout << "YES";
		else 
			cout << "NO";
		if (i != t-1)
			cout << endl;
	}

	return 0;
}