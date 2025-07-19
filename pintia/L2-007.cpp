#include <bits/stdc++.h>
using namespace std;

const int SZ = 10000;

struct dsu {
    std::vector<int> pa;
    std::vector<int> v1; //房产套数
    std::vector<int> v2; //房产面积

    explicit dsu(int size) : pa(size) {
        std::iota(pa.begin(), pa.end(), 0);
        v1.resize(size);
        v2.resize(size);
    }

    int find(int x) {
        return pa[x] == x ? x : (pa[x] = find(pa[x]));
    }

    void unite(int x, int y) {
        pa[find(x)] = find(y);
    }
};

struct E {
	int id;
	int cnt;
	float average;
	float average_s;
	E(int a, int b, float c, float d): id(a), cnt(b), average(c), average_s(d) {}
};

bool cmp(E& a, E& b) {
	if (a.average_s == b.average_s)
		return a.id < b.id;
	return a.average_s > b.average_s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	int m, p1, p2, k, child;
	dsu d(SZ);

	for(unsigned i = 0; i < n; ++i) {
		cin >> m >> p1 >> p2 >> k;

		if (p1 != -1)
			d.unite(p1, m);
		if (p2 != -1)
			d.unite(p2, m);

		for(unsigned j = 0; j < k; ++j) {
			cin >> child;
			d.unite(child, m);
		}
		cin >> d.v1[m] >> d.v2[m];
	}

	bool f[SZ] {}; //去重
	int fa;
	vector<E> ans;

	for(unsigned i = 0; i < SZ; ++i) {
		fa = d.find(i);
		if (f[fa])
				continue;

		if (fa != i) {
			//因为是从0找的，所以找到的第一个有家庭的，就是这个家庭里面家最小的成员编号
			int cnt = 0;
			float hs = 0, s = 0;
			//找所有人
			for(unsigned j = 0; j < SZ; ++j) {
				if (d.find(j) == fa) {
					hs += d.v1[j];
					s += d.v2[j];
					cnt++;
				}
			}
			hs /= cnt;
			s /= cnt;

			ans.emplace_back(i, cnt, hs, s);

			f[fa] = true;
		} else if (d.v1[i] != 0){
			//可能一个人一个家庭
			ans.emplace_back(i, 1, d.v1[i], d.v2[i]);
			f[fa] = true;
		}
	}
	sort(ans.begin(), ans.end(), cmp);

	cout << ans.size() << endl;
	for(unsigned i = 0; i < ans.size(); ++i) {
		cout << setfill('0') << setw(4)
			<< ans[i].id << ' '
			<< ans[i].cnt << ' '
			<< setprecision(3) << fixed
			<< ans[i].average << ' '
			<< ans[i].average_s;

		if (i != ans.size() - 1)
			cout << endl;
	}

	return 0;
}
