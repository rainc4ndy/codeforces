#include <bits/stdc++.h>
using namespace std;

#define mod (300001)
#define ll long long

#define x first
#define y second

//hp, loc
typedef pair<int, int> P;
P v[mod];

bool f(P& a, P& b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ammo, dead, loc;
	bool flag = false;
	ll t, n, k;
	cin >> t;

	vector<bool> ans(t);
	for (int j = 0; j < t; j++) {
		flag = true;

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> v[i].x;
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i].y;
			v[i].y = abs(v[i].y);


			if (v[i].x / k > v[i].y) {
				flag = false;
			}
		}

		if (!flag) {
			ans[j] = flag;
			continue;
		}

		sort(v, v + n, f);
		dead = 0;
		loc = 0;

		while (flag && dead != n) {
			ammo = k; //reload
			for (int i = dead; i < n; i++) {
				if (!ammo)
					break;


				if (v[i].y == loc) {
					flag = false;
					break;
				}

				if (v[i].x > 0) {
					if (ammo >= v[i].x) {
						ammo -= v[i].x; //die
						v[i].x = 0;
						dead++;
					} else {
						v[i].x -= ammo;
						ammo = 0;
					}
				}
			}
			loc++;
		}
		ans[j] = flag;
	}

	for (int i = 0; i < t; i++)
	{
		cout << (ans[i] ? "YES" : "NO");
		if (i != t - 1)
			cout << endl;
	}
	return 0;
}