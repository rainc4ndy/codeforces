#include<stdio.h>
#include<stdlib.h>

long long min(long long x, long long y);
int main(void)
{
	int n;
	scanf("%d", &n);
	int* gao = (int*)malloc(n * sizeof(int));//变长数组：动态内存分配
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &gao[i]);
	}
	long long int max = 0;
	int l = 0, r = n - 1;//双指针，一个从前到后，一个从后到前
	while (l < r)
	{
		if (max < min(gao[r], gao[l]) * (r - l))
		{
			max = min(gao[r], gao[l]) * (r - l);
		}
		if (gao[l] <= gao[r])
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	printf("%lld\n", max);
	free(gao);

	return 0;
}
long long min(long long x, long long y)
{
	return x > y ? y : x;
}