#include <bits/stdc++.h>
using namespace std;

#define mod (100000)
#define ll long long

int v[mod], nxt[mod], pre[mod];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(v, -1, sizeof(v));
	memset(nxt , -1, sizeof(nxt));

	int root, end, n;
	cin >> root >> n;

	int addr;
	int sz = 1;
	for (unsigned i = 0; i < n; ++i) {
		cin >> addr >> v[addr] >> nxt[addr];
		if (nxt[addr] == -1)
			end = addr;
		pre[nxt[addr]] = addr;
		sz++;
	}
	sz /= 2;
	int s = root, e = end;
	while (sz) {
		//e -> s
		cout << setfill('0') << setw(5) << e;
		cout << ' ' << v[e] << ' ';
		if (e == s) {
			cout << -1;
			break;
		}
		else {
			cout << setfill('0') << setw(5) << s << endl;

		}

		cout << setfill('0') << setw(5) << s;
		cout << ' ' << v[s] << ' ';
		if (pre[e] == s) {
			cout << -1;
			break;
		}
		else {
			cout << setfill('0') << setw(5) << pre[e] << endl;
		}

		s = nxt[s];
		e = pre[e];
		sz--;
	}


	return 0;
}