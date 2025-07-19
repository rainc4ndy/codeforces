#include <bits/stdc++.h> 
using namespace std;

struct st {
	string s;
	int sc;
};

bool cmp(st&a , st&b) {
	if (a.sc == b.sc) {
		return a.s.compare(b.s) < 0; //小于0说明 a.s的字典序小于b.s
	}
	return a.sc > b.sc;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n,g,k;
	cin >> n >> g >> k;

	vector<st> v;
	int sum = 0;
	st tmp;
	for(unsigned i = 0; i < n; ++i) {
		cin >> tmp.s >> tmp.sc;
		if (tmp.sc >= 60 && tmp.sc < g) {
			sum += 20;
		} else if (tmp.sc >= g) {
			sum += 50;
		}
		//踩坑
		v.push_back(tmp); //即使不到60分也要加到vector里面，后面需要算排名!
	}

	sort(v.begin(), v.end(), cmp);

	int in = 0, rank = 0;
	int pre = 0;
	cout << sum << endl;

	for(int i = 0; i < v.size() && rank <= k; i++) {
		if (pre != v[i].sc) {
			rank++;
			if (in != 0) {
				rank += in;
				in = 0;
			}
			if (rank > k)
				break;
		} else {
			in++;
		}

		cout << rank << ' ' << v[i].s << ' '  << v[i].sc;
		if (i != v.size() - 1)
			cout << endl;
		pre = v[i].sc;
	} 


	return 0;
}