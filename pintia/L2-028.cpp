#include <bits/stdc++.h> 
using namespace std;

#define SZ (1001)

struct st {
    double fac;
    int id; //id (正数，不管性别)
};

bool cmp(st &a, st&b) {
    return a.fac > b.fac;
}

st da[SZ][SZ] {};

bool sex[SZ];

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n,m,k;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            da[i][j].id = j;
        }
    }

    int v[501];
    for (int i = 0; i < m; i++) {
    	cin >> k;
    	double f = 1.0/k;

    	for (int j = 0; j < k; j++) {
    		cin >> v[j]; //person
    		sex[v[j]] = v[j] > 0;
    		v[j] = abs(v[j]);
    	}
    	for (int j = 0; j < k; j++) {
    		for (int x = 0; x < k; x++) {
    			if (x == j)
    				continue;
                da[j][x].fac += f;
                da[x][j].fac += f;
    		}
    	}
    }

    int a,b;
    cin >> a >> b;
    bool femA = a < 0, femB = b < 0;
    a = abs(a);
    b = abs(b);

    int cur = 0;
    sort(da[a], da[a] + SZ, cmp);
    while (cur < n) {
    	if (sex[da[a][cur].id] == femA)
            cur++;

    	cout << (femA ? a*-1 : a) << ' '
    		<< da[a][cur].id*-1
            << ' ' << da[a][cur].fac
            << endl;
        cur++;
    }

    sort(da[b], da[b] + SZ, cmp);
    cur = 0;
    while (cur < n) {
        if (sex[da[b][cur].id] == femB)
            cur++;

        cout << (femB ? b*-1 : b) << ' '
            << da[b][cur].id*-1
            << ' ' << da[b][cur].fac
            << endl;
        cur++;
    }


	return 0;
}