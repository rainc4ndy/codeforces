#include <iostream>

int main(int argc, char const *argv[]) {

	using namespace std;
	unsigned long long n = 0, m = 0, a = 0;

	cin >> n >> m >> a;

	unsigned long long w = 0, h = 0;

	double cache;

	cache = (double)n / (double)a;
	w = (cache - (unsigned long long)cache > 0) ? cache + 1 : cache;

	cache = (double)m / (double)a;
	h = (cache - (unsigned long long)cache > 0) ? cache + 1 : cache;

	cout << w * h;

	return 0;
}