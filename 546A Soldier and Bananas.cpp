#include <algorithm>
#include <iostream>
#include <math.h>

long long getp(long long num, long long init) {
	if (num == (long long)0)
		return (long long)0;
	using namespace std;
	//cout << "num " << num << "  inint  " << init << endl;
	return init * num + getp(num - 1, init);
}

int main(int argc, char const *argv[]) {
	
	using namespace std;

	// w - wanted
	// k - init price
	// n - money
	long long k, n, w;
	cin >> k >> n >> w;

	long long t = getp(w, k);

	long long b = t - n;

	b = max((long long)0, b);

	cout << b;

	return 0;
}