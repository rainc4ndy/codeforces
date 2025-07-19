#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<ull, ull> P;

void solve() {
	ull n, h, m, u, yy, mm, dd, s1, s2, s3, a = 0, b = 0, c = 0, tot;
	char tmp;
	cin >> n >> h >> m;

	map<int, vector<P>> rec;
	for (int i = 0; i < n; i++) {
		cin >> u;
		cin >> yy >> tmp >> mm >> tmp >> dd;
		cin >> s1 >> tmp >> s2 >> tmp >> s3;
		if (yy == h && m == mm) {
			tot = s1 * 3600 + s2 * 60 + s3;
			rec[dd].emplace_back(u, tot);
		}
	}
	for (auto&it : rec) {
		//for days
		set<ull> m1,m3,m4;
		for (auto&yt : it.y) {
			cout << "yt.y = " << yt.y << endl;
			if (7*3600 <= yt.y && yt.y <= 9*3600) {
				if (m1.find(yt.x) == end(m1)) {
					a++;
					cout << "user " << yt.x << endl;
					m1.insert(yt.x);
				}
			}
			if (18*3600 <= yt.y && yt.y <= 20*3600) {
				if (m1.find(yt.x) == end(m1)) {
					a++;
					m1.insert(yt.x);
				}
			}
			if (11*3600 <= yt.y && yt.y <= 13*3600) {
				if (m3.find(yt.x) == end(m3)) {
					b++;
					m3.insert(yt.x);
				}
			}
			if (22*3600 <= yt.y && yt.y <= 1*3600) {
				if (m4.find(yt.x) == end(m4)) {
					c++;
					m4.insert(yt.x);
				}
			}
		}
	}	
	cout << a << ' ' << b << ' ' << c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();

	return 0;
}