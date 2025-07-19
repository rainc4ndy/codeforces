#include<bits/stdc++.h>
using namespace std;
int n, m;
string s, t;
int first[200001];
int last[200001];
int maxs;
int main()
{
	cin >> n >> m;
	cin >> s >> t;
	s = " " + s;
	t = " " + t;
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (s[++j] != t[i]);
		first[i] = j;
	}
	for (int i = m, j = n + 1; i >= 1; i--)
	{
		while (s[--j] != t[i]);
		last[i] = j;
	}
	for (int i = 1; i <= m - 1; i++)
	{
		maxs = max(maxs, last[i + 1] - first[i]);
	}
	cout << maxs << endl;
	return 0;
}