#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;

	int v;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> v;
		auto p = s.lower_bound(v);
		//如果最大下确界存在，那么删去这个下确界，把新元素作为 "队列" 中的最右端
		if (p != s.end()) {
			s.erase(p);
			s.insert(v);
		} else  {
			//否则只能单独成为一列
			s.insert(v);
		}
	}

	//剩下s内的元素数量即为有多少个 "队列" 的右端
	cout << s.size();
	return 0;
}