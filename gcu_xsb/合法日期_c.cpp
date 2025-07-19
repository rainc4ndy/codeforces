#include <bits/stdc++.h> 

void solve() {
    int m, d;
    scanf("%d%d", &m, &d);

    int v[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m >= 1 && m <= 12 && d >= 1 && d <= v[m]) {
        printf("Yes");
    } else {
        printf("No");
    }
}
int main() {    
	int _ = 1;
	while(_--) solve();
	return 0;
}