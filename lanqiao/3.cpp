#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string v1[10] = {
		"jia",
		"yi",
		"bing",
		"ding",
		"wu",
		"ji",
		"geng",
		"xin",
		"ren",
		"gui"
	};
	string v2[12] = {
		"zi",
		"chou",
		"yin",
		"mao",
		"chen",
		"si",
		"wu",
		"wei",
		"shen",
		"you",
		"xu",
		"hai"
	};

	int y;
	cin >> y;

	int st = 2020;
	int a = 6, b = 0;
	while (st != y) {
		if (st < y) {
			a++;
			b++;
			st++;
		}
		else {
			a--;
			b--;
			st--;
		}
		if (a < 0)
			a = 9;
		else if (a > 9) // Adjusted condition to match the array size
			a = 0;
		if (b < 0)
			b = 11;
		else if (b > 11)
			b = 0;

	}
	cout << v1[a] << v2[b];


	return 0;
}
