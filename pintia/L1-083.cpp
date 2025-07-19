#include <algorithm>
#include <bits/stdc++.h> 
#include <cstdio>
 
using namespace std;

int main() {
    

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int forbid, com, a1, a2;

	cin >> forbid >> com >> a1 >> a2;

	bool b1 = true, b2 = true;

	if (a1 < forbid)
		b1 = false;

	if (a2 < forbid)
		b2 = false;

	int m = min(a1, a2);
	if (a1 == m && a2 >= com) 
		b1 = b1 | b2;
	else if (a2 == m && a1 >= com) 
		b2 = b1 | b2;

	printf("%d-%c %d-%c\n",
		a1, b1 ? 'Y' : 'N',
		a2, b2 ? 'Y' : 'N'
		);

	if (m < forbid && (b1 && b2)) {
		if (a2 < a1)
			printf("qing 1 zhao gu hao 2");
		else
			printf("qing 2 zhao gu hao 1");
	} else {
		if (b1 && b2) {
			printf("huan ying ru guan");
		} else {
			if (!b1 && !b2) {
				printf("zhang da zai lai ba");
			}
			else printf("%d: huan ying ru guan",
				a2 < a1 ? 1 : 2
				);
		}
	}
	return 0;
}