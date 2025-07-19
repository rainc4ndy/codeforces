#include <bits/stdc++.h> 
#include <utility>
#include <vector>
  
#define mod (100001)
#define ll long long

using namespace std;

struct stmove {
	int x;
	int y;
};

int ans[1001] {};

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	int a, b; //a for straight, b other
	int x, y; //king
	int x2, y2; //queen

	for (int z = 0; z < t; z++) {
		cin >> a >> b;
		cin >> x  >> y;
		cin >> x2  >> y2;

		stmove move1[8] = {
			{x + a, y + b},
			{x + a, y - b},
			{x - a, y + b},
			{x - a, y - b},
			{x + b, y + a},
			{x + b, y - a},
			{x - b, y + a},
			{x - b, y - a},
		};

		stmove move2[8] = {
			{x2 + a, y2 + b},
			{x2 + a, y2 - b},
			{x2 - a, y2 + b},
			{x2 - a, y2 - b},
			{x2 + b, y2 + a},
			{x2 + b, y2 - a},
			{x2 - b, y2 + a},
			{x2 - b, y2 - a},
		};

		stmove move3[8] = {};
		bool uni = true;
		for (int i = 0; i < 8; i++) {
			for (int k = 0; k < 8; k++) {
				if (move1[i].x == move2[k].x && move1[i].y == move2[k].y) {

					if (ans[z] == 0) {
						move3[0].x = move1[i].x;
						move3[0].y = move1[i].y;
						ans[z]++;
				    	//cout << move1[i].x << ' ' << move1[i].y << ' ' << move2[k].x << ' ' << move2[k].y << ' '<< endl;
					} else {
						uni = true;
						for (int j = 0; j < ans[z]; j++) {
							if (move1[i].x == move3[j].x && move1[i].y == move3[j].y) {
								uni = false;
								break;
							}
						}
						if (uni) {
							move3[ans[z]].x = move1[i].x;
							move3[ans[z]].y = move1[i].y;
							ans[z]++;
			    			//cout << move1[i].x << ' ' << move1[i].y << ' ' << move2[k].x << ' ' << move2[k].y << ' '<< endl;
						}
					}
					break;
				}
			}
		}
	}

	for (int z = 0; z < t; z++) {
		cout << ans[z];
		if (z != t -1)
			cout << endl;
	}

	return 0;
}