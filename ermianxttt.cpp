#include <stdio.h>

constexpr int MAXN = 600;
int max(int x, int y) {return x > y?x:y;}
int num[MAXN][MAXN];
int main(void) {
    int N,M;
    scanf("%d %d", &N, &M);
    
    int i,j,mx = 0;
    for (i =0;i<N;i++) {
        for (j =0;j<M;j++) {
            scanf("%d", &num[i][j]);
            mx = max(mx,num[i][j]);
        }
    }
    for (i = 0; i<N;i++) {
        for (j = 0; j < M; j++) {
            if (num[i][j] == mx) {
                printf("%d %d %d", mx,j+1,N-i);
                return 0;
            }
        }
    }
    return 0;
}