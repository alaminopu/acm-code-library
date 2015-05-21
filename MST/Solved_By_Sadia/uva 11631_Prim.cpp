#include<bits/stdc++.h>
using namespace std;
#define MAXN 200006
#define INF 1LL<<60
vector < pair < int , int > > Edges[MAXN];
bool vis[MAXN];
long long cost[MAXN];
long long prim(int N)
{
    priority_queue < pair < int , int > > PQ;
    PQ.push(make_pair(0,1));
    int node, c, now, i;
    long long ret = 0;
    while (!PQ.empty())
    {
        node = PQ.top().second, c = PQ.top().first;
        PQ.pop();
        if (vis[node]) continue;
        vis[node] = true;
        ret -= c;
        cost[1] = 0;
        for (i=0; i<Edges[node].size(); ++i)
        {
            now = Edges[node][i].first;
            c = Edges[node][i].second;
            if (vis[now]) continue;
            if (c < cost[now]) PQ.push(make_pair(-c, now)), cost[now] = c;
        }
    }
    return ret;
}
int main()
{
    int N,M,i,x,y,c;
    long long C;
    while (scanf("%d %d", &N, &M) != EOF && N)
    {
        for (i=1; i<=N; ++i) Edges[i].clear(), vis[i] = false, cost[i] = INF;
        C = 0;
        while (M--)
        {
            scanf("%d %d %d", &x, &y, &c);
            ++x, ++y;
            Edges[x].push_back(make_pair(y,c));
            Edges[y].push_back(make_pair(x,c));
            C += c;
        }
        printf("%lld\n", C-prim(N));
    }
    return 0;
}
