#include <cstdio>
#include <cstring>
#include <string>

char v[100000] = "1";
char d[100000];
int current_size = 1;

//最多数据到40

void gen_rle(int sz) {
    int l = 0, r = 0;
    int cur = 0;

    while (r < sz) {
        while (r < sz && v[l] == v[r]) {
            r++;
        }
        int cnt = r - l;
        char buffer[128];
        
        int top = sprintf(buffer, "%d%c", cnt, v[l]);
        
        for (int i = 0; i < top; i++) {
            d[cur++] = buffer[i];
        }
        l = r;
    }

    d[cur] = '\0';
    memcpy(v, d, cur);
    current_size = cur;
}

void solve() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		gen_rle(current_size);
	}
	printf("%s", v);
}

int main() {    
	int _ = 1;
	while(_--) solve();
	return 0;
}