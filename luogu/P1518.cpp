#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define GROUND '.'
#define BARRIER '*'
#define COW 'C'
#define FARMER 'F'

char m[10][10] {};

int p1, p2;
int f1, f2;
int dir_cow = 0, dir_farmer = 0;
enum {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

void move(int &pos1, int &pos2, int &direction) {
	int n1 = pos1, n2 = pos2;
	switch (direction) {
	case UP: {
		n1--;
		break;
	}
	case DOWN: {
		n1++;
		break;
	}
	case LEFT: {
		n2--;
		break;
	}
	case RIGHT: {
		n2++;
		break;
	}
	}
	if (n1 < 0 || n1 >= 10 || n2 < 0 || n2 >= 10) {
		direction = ++direction % 4;
		return;
	}
	if (m[n1][n2] == BARRIER) {
		direction = ++direction % 4;
		return;
	}

	pos1 = n1; pos2 = n2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (unsigned i = 0; i < 10; ++i) {
		for (unsigned j = 0; j < 10; ++j) {
			cin >> m[i][j];
			if (m[i][j] == COW ) {
				p1 = i;
				p2 = j;
			} else if (m[i][j] == FARMER) {
				f1 = i;
				f2 = j;
			}
		}
	}

	int minute = 0;

	while (minute < 160000) {
		move(p1, p2, dir_cow);
		move(f1, f2, dir_farmer);

/*		for (unsigned i = 0; i < 10; ++i) {
			for (unsigned j = 0; j < 10; ++j) {
				if (i == p1 && j == p2) {
					cout << 'C';
				} else if (i == f1 && j == f2) {
					cout << 'F';
				} else {
					cout << m[i][j];
				}
			}
			cout << endl;
		}*/

		minute++;
		if (p1 == f1 && p2 == f2) {
			break;
		}

	}

	if (minute == 160000)
		cout << 0;
	else
		cout << minute;
	return 0;
}

