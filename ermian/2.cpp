#include <stdio.h>
#include <cstring>
int main(void)
{
    char ch[100000];
    int i;
    scanf("%s",ch);
    i = strlen(ch);
    
    while(i >= 0)
    {
        printf("i = %d;\n", i);
    	printf("%c",ch[i - 1]);
    	i--;
	}
    
    return 0;
}