#include <bits/stdc++.h>
#include <valarray>

using namespace std;

long long binpow(long long a, long long b) {
	if (b == 0) return 1;
	long long res = binpow(a, b / 2);
	if (b % 2)
		return res * res * a;
	else
		return res * res;
}

class BigInt {
public:
	static const int SZ = 256;
	int v[SZ];
	int len;

	BigInt() { clear(); }
	BigInt(string bin) {
		memset(this, 0, sizeof(BigInt));
		BigInt b;
		for (int i = 0; i < bin.size(); i++) {
			if (bin[i] == '1') {
				b.clear();
				b.set(binpow(2, bin.size() - i - 1));
				add(b);
			}
		}
	}

	void clear() {
		len = 0;
		memset(v, 0, sizeof(v));
	}

	void set(long long num) {
		len = 0;
		while (num != 0) {
			v[SZ - (++len)] = num % 10;
			num /= 10;
		}
	}

	void bin() {
		stringstream ss;
		for (int i = SZ - len; i < SZ; ++i)
			ss << v[i];
		bitset<SZ> b(atoi(ss.str().c_str()));
		string s = b.to_string();
		for (int i = 0; i < SZ; ++i) {
			if (s[i] == '1') {
				cout << s.substr(i, SZ - i);
				return;
			}
		}
		cout << 0;
	}
	void dec() {
		for (int i = SZ - len; i < SZ; ++i) {
			cout << v[i];
		}
	}
	string dec_s() {
		stringstream ss;
		for (int i = SZ - len; i < SZ; ++i) {
			ss << v[i];
		}
		return ss.str();
	}
	void hex() {

	}
	void add(BigInt &b) {
		int carry = 0;
		if (len < b.len)
			len = b.len;
		for (int i = SZ - 1; i >= 0; --i) {
			v[i] += b.v[i] + carry;
			if (v[i] > 9) {
				carry = 1;
				v[i] %= 10;
			}
			else carry = 0;
		}
		if (v[SZ - 1 - len])
			len++;
	}

	void mul(BigInt &BB) {
		int v1[SZ] {}, v2[SZ] {}, ans[SZ] {};
		string a = dec_s(), b = BB.dec_s();

		int p1 = SZ - 1, p2 = SZ - 1;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (auto it : a)
			v1[p1--] = it - '0';
		for (auto it : b)
			v2[p2--] = it - '0';

		int *lesser = p1 > p2 ? v1 : v2;
		int *greater = p1 > p2 ? v2 : v1;

		int mx = max(p1, p2);
		int mi = min(p1, p2);

		int loc = 0;
		int vaild = SZ - 1; //有效位置
		int carry = 0, carry_p = 0; //乘法进位，加法进位

		//逆序数组，模拟乘法计算
		for (int i = SZ - 1; i >= mx; i--) { //用位数小的去乘大的，位数越小，那么前置0越多
			loc = i;
			for (int j = SZ - 1; j >= mi; j--) {
				ans[loc] += ((lesser[i] * greater[j]) % 10) + carry;
				carry = (lesser[i] * greater[j]) / 10;

				//检查加法进位
				ans[loc] += carry_p;
				carry_p = ans[loc] / 10;
				ans[loc] %= 10;

				if (ans[loc])
					vaild = loc;
				loc--;
			}
		}

		len = SZ - vaild;
		memcpy(v, ans, sizeof(ans));
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "numeric_limits<long long>().max() * numeric_limits<long long>().max() = " << endl;
	BigInt a;
	a.set(numeric_limits<long long>().max());
	a.bin();

	cout << endl << endl;
	a = BigInt("111111111111111111111111111111");
	a.dec();

	return 0;

	cout << "BigInt b(\"1111\"); BigInt b2(\"1111\");" << endl;
	BigInt b("1111");
	BigInt b2("1111");
	cout << "b.mul(b2) = ";
	b.mul(b2);
	b.dec();

	cout << endl << endl;
	cout << "numeric_limits<long long>().max(): " << endl << numeric_limits<long long>().max() << endl;
	cout << "numeric_limits<long long>().max() * numeric_limits<long long>().max() = " << endl;
	BigInt c, d;
	c.set(numeric_limits<long long>().max());
	d.set(numeric_limits<long long>().max());
	c.mul(d);
	c.dec();

	return 0;
}
