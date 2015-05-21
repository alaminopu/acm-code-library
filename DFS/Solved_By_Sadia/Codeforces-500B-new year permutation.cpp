#include<bits/stdc++.h>
using namespace std;
#define MAXN 306
vector < int > Edges[MAXN];
int arr[MAXN];
char str[MAXN];
bool vis[MAXN];
vector < int > Vidx, Vval;
void dfs(int node)
{
    if (vis[node]) return;
    vis[node] = true;
    Vidx.push_back(node);
    Vval.push_back(arr[node]);
    int i;
    for (i=0; i<Edges[node].size(); ++i) dfs(Edges[node][i]);
}
int main()
{
    int N,i,j;
    while (scanf("%d", &N) != EOF)
    {
        for (i=1; i<=N; ++i) scanf("%d", &arr[i]);
        for (i=1; i<=N; ++i)
        {
            scanf("%s", str+1);
            Edges[i].clear();
            for (j=1; j<=N; ++j)
            {
                if (str[j] == '1') Edges[i].push_back(j);
            }
        }
        for (i=1; i<=N; ++i)
        {
            if (vis[i]) continue;
            Vidx.clear(), Vval.clear();
            dfs(i);
            sort (Vidx.begin(), Vidx.end());
            sort (Vval.begin(), Vval.end());
            for (i=0; i<Vidx.size(); ++i) arr[Vidx[i]] = Vval[i];
        }
        for (i=1; i<=N; ++i) printf("%d ", arr[i]);
        puts("");
    }
    return 0;
}
