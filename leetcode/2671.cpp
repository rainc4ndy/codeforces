#include <bits/stdc++.h>
using namespace std;

class FrequencyTracker {
private:
	int um[100001]; //um[j] 数字j 的出现的次数
	int f[100001]; //f[i] 频率i 有多少种数字的组合
public:
	FrequencyTracker() {
		//um = new int[500];
		//f = new int[500];
		memset(um, 0, sizeof(um));
		memset(f, 0, sizeof(f));
	}

	void add(int number) {
		if (f[um[number]])
			f[um[number]]--;
		++f[++um[number]];
	}

	void deleteOne(int number) {
		if (um[number]) {
			f[um[number]]--;
			++f[--um[number]];
		}
	}

	bool hasFrequency(int frequency) {
		return f[frequency];
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	return 0;
}