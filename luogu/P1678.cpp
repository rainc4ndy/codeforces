#include <bits/stdc++.h> 
using namespace std;

int m, n;
vector<int> sc;

int f(int trg) {
    int l = 0, r = sc.size() - 1, m;
    if (trg <= sc.front()) return sc.front(); // 如果目标值小于等于数组第一个元素
    if (trg >= sc.back()) return sc.back(); // 如果目标值大于等于数组最后一个元素

    while (l <= r) {
        m = l + (r - l) / 2;
        if (sc[m] < trg) {
            l = m + 1;
        } else if (sc[m] > trg) {
            r = m - 1;
        } else {
            return sc[m]; // 直接找到目标值，返回
        }
    }

    // 循环结束时，l 和 r 分别指向大于和小于目标值的最接近的两个元素
    // 需要检查这两个元素哪个更接近目标值
    if (l < sc.size() && std::abs(sc[l] - trg) < std::abs(sc[r] - trg)) {
        return sc[l];
    } else {
        return sc[r];
    }
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	cin >> m >> n;

	sc.resize(m);

	int sum = 0;
	int p;

	for (int i = 0; i < m; i++) {
		cin >> sc[i];
	}
	sort(sc.begin(), sc.end());

	for (int i = 0; i < n; i++) {
		cin >> p;
		sum += abs(p - f(p));
	}

	cout << sum;
	return 0;
}