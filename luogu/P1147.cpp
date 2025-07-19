#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int m;
	cin >> m;

	int i = 1, j = 1, sum = 1;
	
	while (i <= j) {
		if (sum < m) {
			j++; //先加上j因为 一开始默认sum是1，要从2开始加
			sum += j;
		} else if (sum > m) {
			sum -= i;
			i++;
		} else {
			if (i != j)
				cout << i << ' ' << j << endl;
			sum -= i; //减去之后 可以继续向前移动
			i++;
		}
	}

	return 0;
}