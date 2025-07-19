#include <bits/stdc++.h>
using namespace std;


#define mod (100001)
#define ll long long
int fa[mod];

void dsu_init() {
	for(unsigned i = 0; i < mod; ++i) {
		fa[i] = i;
	}
}

int dsu_find(int i) {
	if (i == fa[i])
		return i;
	return dsu_find(fa[i]);
}

void dsu_union(int i, int j) {
	int a = dsu_find(i),
		b = dsu_find(j);
	fa[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dsu_init();

    dsu_union(2, 4);
    dsu_union(3, 4);
    dsu_union(4, 10);

    cout << dsu_find(3);

	return 0;
}
