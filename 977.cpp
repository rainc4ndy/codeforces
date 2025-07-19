#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	long long  n, k;
	cin >> n >> k;

	
	for (int i = 0; i < k; ++i)
	{
		if (n % 10 != 0) {
			n--;
		} else {
			n /= 10;
		}
	}

	cout << n;

	return 0;
}