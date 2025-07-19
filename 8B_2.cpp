#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=205;
int graph[MAXN][MAXN];//记录一个格子是否走过。
char input[MAXN];
int x=MAXN/2,y=MAXN/2;//将初始x与y都赋值为地图中央。
int main()
{
	scanf("%s",&input);
	graph[x][y]=1;
	for(int i=0;i<strlen(input);i++)
	{
		char move=input[i];
		if(move=='U')//移动，修改坐标。
		{
			x--;
		}
		else if(move=='D')
		{
			x++;
		}
		else if(move=='L')
		{
			y--;
		}
		else if(move=='R')
		{
			y++;
		}
		if(graph[x][y])//对应情况1。
		{
			printf("BUG\n");
			return 0;
		}
		if(graph[x-1][y]+graph[x+1][y]+graph[x][y-1]+graph[x][y+1]>1)//对应情况2。
		{
			printf("BUG\n");
			return 0;
		}
		graph[x][y]=1;//标记已走过。
	}
	printf("OK\n");
	return 0;
}