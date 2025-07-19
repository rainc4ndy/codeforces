#include <bits/stdc++.h>
#include <sstream>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;
#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"
#define debug(x) cout << #x << ' ' << x << endl;
#define debug1(x)                     \
    RED;                              \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug2(x)                     \
    GREEN;                            \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug3(x)                     \
    BLUE;                             \
    cout << #x << ' ' << x << endl; \
    RESET;


#define int ll

struct Info {
	int mi;
	Info(int y) : mi(y) {};
	Info() :  mi(0x3f3f3f3f) {};
	friend Info operator+(const Info &a, const Info &b) {
        return Info(min(a.mi, b.mi));
    }
};

struct SegmentTree {
    int n;
    std::vector<int> tag;
    std::vector<Info> info;
    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void add(int p, int v) {
        tag[p] += v;
        info[p].mi += v;
    }
    void push(int p) {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return {};
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }
    
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            return add(p, v);
        }
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeAdd(int x, int y, int v) {
        rangeAdd(1, 0, n, x, y, v);
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }
};

void solve() {
	int n;
	cin >> n;

	SegmentTree st(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.modify(i, {x});
	}

	int q; 
	cin >> q;
	cin.ignore(); 

	for (int i = 0; i < q; i++) {
		string s;
		getline(cin, s);

		stringstream ss(s);
		std::vector<int> vec;
	    int num;
	    while (ss >> num) {
	        vec.push_back(num);
	    }
	    if (vec.size() == 2) {
	    	if (vec[0] <= vec[1])
		    	cout << st.query(vec[0],vec[1]+1).mi << endl;
		    else {
		    	int x = st.query(vec[0],n).mi, y = st.query(0,vec[1]+1).mi;
		    	cout << min(x, y) << endl;
		    }
	    } else {
	    	if (vec[0] <= vec[1])
		    	st.rangeAdd(vec[0], vec[1]+1, vec[2]);
		    else {
		    	st.rangeAdd(vec[0],n,vec[2]);
		    	st.rangeAdd(0,vec[1]+1,vec[2]);
		    }
	    }
	}
}

signed main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}