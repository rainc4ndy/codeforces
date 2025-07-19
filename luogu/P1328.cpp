#include <bits/stdc++.h>
#include <vector>
using namespace std;

int table[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, na, nb;
	cin >> n >> na >> nb;

	vector<int> oa(na), ob(nb);

	for(unsigned i = 0; i < na; ++i) {
		cin >> oa[i];
	}
	for(unsigned i = 0; i < nb; ++i) {
		cin >> ob[i];
	}

	int pa = 0, pb = 0, r = 0, s1 = 0, s2 = 0;
	for(unsigned i = 0; i < n; ++i) {
		s1 += table[oa[pa % na]][ob[pb % nb]];
		s2 += table[ob[pb % nb]][oa[pa % na]];
		pa++; pb++;
	}

	cout << s1 << ' ' << s2;

	return 0;
}
