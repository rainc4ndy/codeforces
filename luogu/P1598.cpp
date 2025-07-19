#include <bits/stdc++.h>

int main() {

	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[256] {};


	string tmp;

	for (int i = 0; i < 4; ++i)
	{
		getline(cin, tmp);
		for (auto it : tmp) {
			arr[(int)it]++;
		}
	}

	int mx = 0;

	for (int j = 'A'; j <= 'Z'; j++)
	{
		mx = max(mx, arr[j]);
	}

	int mx2 = 0;

	for (int i = mx; i > 0; --i)
	{
		for (int j = 'A'; j <= 'Z'; j++)
		{
			mx2 = max(mx2, arr[j]);
			if (arr[j] >= i)
				cout << "*";
			else if (arr[j] <= mx2)
				cout << ' ';
			if (j != 'Z')
				cout << ' ';
		}
		cout << endl;
	}
	for (int j = 'A'; j <= 'Z'; j++)
	{
		cout << (char)j;
		if (j != 'Z')
			cout << ' ';
	}

	return 0;
}
