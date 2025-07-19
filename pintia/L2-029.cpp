#include <bits/stdc++.h> 
using namespace std;

const int SZ = 10001;

bool d[SZ][SZ] {}; //d[i][j] 表示j依附于i
int d2[SZ] {}; //d2[i] 依附于它的的幸福数的个数

set<int> u;
bool sq(int o, int n) {
	int sum = 0;
	int tmp;
	while (n) {
		tmp = n%10;
		sum += tmp*tmp;

		n /= 10;
	}

	if (sum == 1)
		return true;
	if (u.count(sum))
		return false;

	u.insert(sum);

	if (!sq(o, sum)) {
		d2[o] = 0;
		return false;
	} 
	d[o][sum] = true;
	if (n != o)
		d2[o]++;

	return true;
}

void init() {
	for(unsigned i = 1; i <= 100; ++i) {
		if (d2[i]==0) {
    		u.clear();
			cout << "sq(i) = " << sq(i, i) << endl;
			cout << "d2[i] = " << d2[i] << endl;
		}
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    init();

    int a, b;
    cin >> a >> b;

    vector<int> ans;

    for(unsigned i = a + 1; i < b; ++i) {
    	if (d2[i]) {
    		ans.push_back(i);
    	}
    }

    for(unsigned i = 0; i < ans.size(); ++i) {
    	cout << ans[i];
    	if (i != ans.size() - 1)
    		cout << endl;
    }

	return 0;
}