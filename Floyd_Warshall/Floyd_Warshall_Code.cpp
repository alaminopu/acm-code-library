#include<bits/stdc++.h>
using namespace std;
#define MAXN 106
#define INF 1000000000
int fw[MAXN][MAXN];
void init(int N)
{
    int i,j;
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=N; ++j) fw[i][j] = INF;
        fw[i][i] = 0;
    }
}
void floyd_warshall(int N)
{
    int i,j,k,temp;
    for (k=1; k<=N; ++k)
    {
        for (i=1; i<=N; ++i)
        {
            for (j=1; j<=N; ++j)
            {
                temp = fw[i][k] + fw[k][j];
                if (temp < fw[i][j]) fw[i][j] = temp;
            }
        }
    }
}
int main()
{
    int N,M,x,y,c,i,j;
    while (scanf("%d %d", &N, &M) != EOF)
    {
        init(N);
        while (M--)
        {
            scanf("%d %d %d", &x, &y, &c);
            fw[x][y] = fw[y][x] = c;
        }
        floyd_warshall(N);
    }
    return 0;
}
