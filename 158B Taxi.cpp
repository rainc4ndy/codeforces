#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {

	using namespace std;

	int n;
	cin >> n;

	vector<int> v;
	int tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		v.push_back(tmp);
	}

	int count = 0; //清空的组数
	for (int i = 0; i < n; ++i) {
		//check if they just fit
		bool fited = false;
		for (int k = 4; k >= 1; k--) { //从大到小装
			for (int j = 0; j < n; ++j) { //从头找
				if (v[j] == 0 || i == j)
					continue;
				if (v[j] + v[i] == k) {
					//cout << "v[j] = " << v[j] << endl << " j = " << j << endl << " k = " << k << endl;
					v[j] += v[i];
					v[i] = 0; //清理掉了一组 
					count++;

					fited = true;
					break;
				}
			}
			if (fited) {
				break;
			}
		}
	}

	cout << n - count;

	return 0;
}