#include <iostream>

int binarySearch(int *num, int goal, int low, int high) {
	int m = 0;
	while (low < high) {
		m = (low + high) / 2;

		if (num[m] == goal) {
			return m; 
		}

		if (num[m] < goal) {
			low = l;
		}
	}
}

int main(int argc, char const *argv[]) {
	
	using namespace std;



	return 0;
}