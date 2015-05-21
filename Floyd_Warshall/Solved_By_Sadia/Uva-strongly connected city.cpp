#include<bits/stdc++.h>
using namespace std;
#define MAXN 406
#define INF 1000000000
int fw[MAXN][MAXN];
char hor[MAXN], ver[MAXN];
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
int findidx(int N, int M, int x, int y)
{
    return (x-1)*M + y;
}
void addEdge(int N, int M, int x1, int y1, int x2, int y2)
{
    if (x2 >= 1 && x2 <= N && y2 >= 1 && y2 <= M) fw[findidx(N,M,x1,y1)][findidx(N,M,x2,y2)] = 1;
}
bool check(int N)
{
    int i,j;
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=N; ++j)
        {
            if (fw[i][j] >= INF) return false;
        }
    }
    return true;
}
int main()
{
    int N,M,i,j;
    while (scanf("%d %d", &N, &M) != EOF)
    {
        scanf("%s %s", hor+1, ver+1);
        init(N*M);
        for (i=1; i<=N; ++i)
        {
            for (j=1; j<=M; ++j)
            {
                if (hor[i] == '>') addEdge(N,M,i,j,i,j+1);
                else addEdge(N,M,i,j,i,j-1);
                if (ver[j] == '^') addEdge(N,M,i,j,i-1,j);
                else addEdge(N,M,i,j,i+1,j);
            }
        }
        floyd_warshall(N*M);
        puts(check(N*M) ? "YES" : "NO");
    }
    return 0;
}
