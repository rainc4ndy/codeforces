#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int cmp_swap(const void* e1, const void* e2)
{
	return *(int*)e2 - *(int*)e1;
}

int solve() {

}

int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}