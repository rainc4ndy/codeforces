#include <bits/stdc++.h> 

using namespace std;

#define mod (100001)
#define ll long long

typedef struct P {	
	string s;
	int sum, uni;
}P;

bool f(P& a, P& b) {
	if (a.uni == b.uni) 
		return a.sum < b.sum;
	return a.uni > b.uni;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	set<ll> v;
	vector<P> l;

	ll g;
	P p;

	for(unsigned i = 0; i < n; ++i) {
		v.clear();
		cin >> p.s >> p.sum;
		for(unsigned j = 0; j < p.sum; ++j) {
			cin >> g;
			v.insert(g);
		}
		p.uni = v.size();
		l.push_back(p);
	}
	sort(l.begin(), l.end(), f);

	//如果有并列，则输出标签出现次数平均值最小的那个
	for(unsigned i = 0; i < 3; ++i) {
		cout << (i < l.size() ? l[i].s : "-");
		if (i != 2)
			cout << ' ';
	}

	return 0;
}