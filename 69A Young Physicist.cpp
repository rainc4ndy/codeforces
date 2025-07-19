#include <iostream>
#include <vector>

struct matrix { 
	int x, y, z;
};

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int num;
	cin >> num;

	vector<matrix> v;

	for (int i = 0; i < num; ++i) {
		matrix cache;
		cin >> cache.x >> cache.y >> cache.z;
		v.push_back(cache);
	}

	int s1 = 0, s2 = 0, s3 = 0;

	for (int i = 0; i < num; ++i) {
		s1 += v[i].x;
		s2 += v[i].y;
		s3 += v[i].z;
	}

	cout << ((s1 == 0 && s2 == 0 && s3 == 0) ? "YES" : "NO");

	return 0;
}