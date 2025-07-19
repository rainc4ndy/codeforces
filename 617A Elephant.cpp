#include <cmath>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int x;
	cin >> x;

	float steps = (float)x / 5;
	cout << ceilf(steps);


	return 0;
}	