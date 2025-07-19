#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

vector<vector<int>> a, b;
vector<P> pa(mod), pb(mod);

//sax[i] 表示在a中取第i行的排列的哈希值（已排序）
//say[i] 表示在a中取第i列的排列的哈希值（已排序）
vector<size_t> sax, say;
vector<size_t> sbx, sby;

void solve() {
	int n, m;
	cin >> n >> m;

	pa.clear();
	a.resize(n);
	for (int i = 0; i < n;i++) {
		a[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			pa[a[i][j]] = {i, j};
		}
	}

	pb.clear();
	b.resize(n);
	for (int i= 0; i< n;i++) {
		b[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			pb[b[i][j]] = {i, j};
		}
	}

	sax.resize(n);
	say.resize(m);
	for (int i = 0; i < n; i++) {
		vector<int> r(m);
		for (int j = 0; j < m; j++) {
			r[j] = a[i][j];
		}
		sort(begin(r), end(r));
		stringstream ss;
		for (auto it : r) ss << it; 
		sax[i] = hash<string>{}(ss.str());
	}
	for (int i = 0; i < m; i++) {
		vector<int> r(n);
		for (int j = 0; j < n; j++) {
			r[j] = a[j][i];
		}
		sort(begin(r), end(r));
		stringstream ss;
		for (auto it : r) ss << it; 
		say[i] = hash<string>{}(ss.str());
	}

	sbx.resize(n);
	sby.resize(m);
	for (int i = 0; i < n; i++) {
		vector<int> r(m);
		for (int j = 0; j < m; j++) {
			r[j] = b[i][j];
		}
		sort(begin(r), end(r));
		stringstream ss;
		for (auto it : r) ss << it; 
		sbx[i] = hash<string>{}(ss.str());
	}
	for (int i = 0; i < m; i++) {
		vector<int> r(n);
		for (int j = 0; j < n; j++) {
			r[j] = b[j][i];
		}
		sort(begin(r), end(r));
		stringstream ss;
		for (auto it : r) ss << it; 
		sby[i] = hash<string>{}(ss.str());
	}

	for (int i = 1; i <= n*m; i++) {
		if (!(sax[pa[i].x] == sbx[pb[i].x] && say[pa[i].y] == sby[pb[i].y])) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}