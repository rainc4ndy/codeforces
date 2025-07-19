#include <bits/stdc++.h> 
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;


struct node {
	ll freq;
	node *lch, *rch;
	bool vir;
	node(ll x) : freq(x), lch(nullptr), rch(nullptr), vir(false) {}
};

struct cmp {
	bool operator()(node*a, node*b) {
		return a->freq > b->freq;
	}
};

ll ans = 0;

void f(node *x, ll depth) {
	if (!x)
		return;
	if (!x->vir){
		ans += depth* x->freq;
	}
	f(x->lch, depth+1);
	f(x->rch, depth+1);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	ll n;
	cin >> n;

	priority_queue<node*, vector<node*>, cmp> pq;
	ll tmp;

	for (ll i = 0; i < n;i++) {
		cin >> tmp;
		pq.push(new node(tmp));
	}

	while (pq.size() != 1) {
		node *l = pq.top();
		pq.pop();

		node *r = pq.top();
		pq.pop();

		node *d = new node(l->freq + r->freq);
		d->lch = l;
		d->rch = r;
		d->vir = true;

		pq.push(d);
	}

	f(pq.top(), 0);
	cout << ans;

	return 0;
}