#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    char c;
    int x, y;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> c;
			if (c == '8' &&
				 i != 0 && i != 8 &&
				 j != 0 && j != 8) {
				x = i;
				y = j;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << (i == x && j == y ? '8' : '*');
		}
		cout << endl;
	}
	return 0;
}