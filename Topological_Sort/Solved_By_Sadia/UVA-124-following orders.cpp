#include<bits/stdc++.h>
using namespace std;
#define MAXN 27
#define MAXL 106
int in[MAXN];
vector < int > Edges[MAXN];
bool vis[MAXN], taken[MAXN];
char str[MAXL];
vector < int > V;
int C;
void bktk(int node)
{
    int i;
    V.push_back(node);
    //for (i=0; i<V.size(); ++i)printf("%d ", V[i]); puts("");
    if (V.size() == C)
    {
        for (i=0; i<V.size(); ++i) putchar(V[i]+'a');
        puts("");
        V.pop_back();
        return;
    }
    taken[node] = true;
    for (i=0; i<Edges[node].size(); ++i) --in[Edges[node][i]];
    for (i=0; i<26; ++i)
    {
        if (vis[i] && !taken[i] && in[i] == 0) bktk(i);
    }
    taken[node] = false;
    for (i=0; i<Edges[node].size(); ++i) ++in[Edges[node][i]];
    V.pop_back();
}
int main()
{
    char *ch;
    int x,y,i;
    while (gets(str))
    {
        memset(vis, false, sizeof(vis));
        memset(in, 0, sizeof(in));
        ch = strtok(str, " ");
        C = 0;
        while (ch != NULL)
        {
            x = *ch - 'a';
            vis[x] = true;
            Edges[x].clear();
            ++C;
            ch = strtok(NULL, " ");
        }
        gets(str);
        ch = strtok(str, " ");
        while (ch != NULL)
        {
            x = *ch - 'a';
            ch = strtok(NULL, " ");
            y = *ch - 'a';
            Edges[x].push_back(y);
            ++in[y];
            ch = strtok(NULL, " ");
        }
        V.clear();
        memset(taken, false, sizeof(taken));
        for (i=0; i<26; ++i)
        {
            if (vis[i] && in[i] == 0)
            {
                //printf("cll with %d\n", i);
                bktk(i);
                //puts("--");
            }
        }
    }
    return 0;
}
