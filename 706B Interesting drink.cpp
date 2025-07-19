#include <array>
#include <functional>
#include <iostream>
#include <algorithm>

#define mod (100001)

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int shops;
	cin >> shops;
	int price[mod];
	for (int i = 0; i < shops; i++) {
		cin >> price[i];
	}
	
	sort(price, price + shops);

	int days;
	cin >> days;
	long long coins[mod];

	for (int i = 0; i < days; i++) {
		cin >> coins[i];
	}

	for (int i = 0; i < days; i++) {

		int result = upper_bound(price, price + shops, coins[i]) - price;
		cout << result;
		if (i != days - 1)
			cout << endl;
	}

	return 0;
}