#include <bits/stdc++.h> 
#include <algorithm>
#include <stdexcept>
#include <type_traits>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	int length[3];
	for (int i = 0; i < 3; i++)
		cin >> length[i];

	sort(length, length + 3);

	int total = 1;
	while (true) {
		if (total == 1) {
			for (int i = 0; i < 3; i++) {
				if (length[i] == n) {
					break;
				}
			}
		} else {
			for (int i = 0; i < 3; i++) {
				for (int k = 0; k < total; k++) {
					
				}
			}
		}	
		total++;
	}

	cout << total;



	//Print a single number — the maximum possible number of ribbon pieces. 
	//It is guaranteed that at least one correct ribbon cutting exists.	

	return 0;
}