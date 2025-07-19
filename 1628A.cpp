#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n;
vector<int> v[N], mex;
int lb(int x, int L) {
	int l = 0, r = v[x].size() - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (v[x][mid] <= L)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return (l >= v[x].size()) ? (n + 1) : v[x][l];
}

int main() {
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n); mex.clear();
		for (int i = 0; i <= n; i++)v[i].clear();
		for (int i = 1, x; i <= n; i++)
		{
			scanf("%d", &x);
			v[x].push_back(i);
		}
		int l = 0;
		while (l < n)
		{
			int r = l + 1;
			for (int i = 0; i <= n; i++)
			{
				int p = lb(i, l);
				if (p > n)
				{
					mex.push_back(i);
					break;
				}
				r = max(p, r);
			}
			l = r;
		}
		printf("%d\n", mex.size());
		for (int i = 0; i < mex.size(); i++)
			printf("%d ", mex[i]);
		putchar('\n');
	}
}