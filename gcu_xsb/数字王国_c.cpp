#include <cmath>
#include <cstdio>
#include <cstring>

bool is_prime(int x) {
	if (x <= 1)
		return false;
	if (x == 2)
		return true;
	if (x % 2 == 0) //对偶数因子全部判断一次
		return false;
	for (int i = 3; i <= sqrt(x); i += 2) { //对奇数因子全部判断一次
		if (x % i == 0)
			return false;
	}
	return true;
}

#define MAXN 1001
bool ok[MAXN];

void solve() {
	int n;
	scanf("%d", &n);

	char buffer[128];
	scanf("%s", buffer);
	int len = strlen(buffer);

	// 获取全部质数
	int ans = 0, ans_s = 0;
	for (int i = 0; i<=n;i++) {
		if ((ok[i] = is_prime(i))) {
			ans++;
		}
	}

	for (int i = 0; i<=n;i++) {
		if (ok[i]) {
			int tmp = i, sz = 0;
			while(tmp) {
				tmp /= 10;
				sz++;
			}
			// if adding a char, len is still a prime
			if (ok[sz+1]) {
				//multiply the whole string with this prime
				ans_s += len;
			}
		}
	}
	printf("%d %d", ans, ans_s);
}

int main() {
	int _ = 1;
	while (_--) solve();
	return 0;
}