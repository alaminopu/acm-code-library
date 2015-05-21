#include <bits/stdc++.h>
#define maxn 105
#define INF 99999999

using namespace std;

struct edge{
    int u;
    int w;
    edge(int a, int b){
        u = a;
        w = b;
    }

    bool operator < (const edge &that) const{
        return w > that.w;
    }
};

vector<int> G[maxn], cost[maxn];
int dist[maxn];

void dijkstra(int exit_cell, int time){
    for(int i=0; i<=maxn; i++){
        dist[i] = INF;
    }

    priority_queue<edge> q;
    q.push(edge(exit_cell, 0));
    dist[exit_cell]=0;

    while(!q.empty()){
        edge top = q.top(); q.pop();
        int u = top.u;
        if(dist[u] > time) break;

        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            if(dist[u]+ cost[u][i] < dist[v]){
                dist[v] = dist[u] + cost[u][i];
                q.push(edge(v, dist[v]));
            }
        }

    }

}

int main(){
    //freopen("in.txt", "r", stdin);

    int cas, N, E, T, M, x, y, z, ret;
    cin >> cas;
    while(cas--){
        cin >> N >> E >> T >> M;
        for(int i=0; i<M; i++){
            cin >> x >> y >> z;
            G[x].push_back(y);
            G[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }

        dijkstra(E,T);
        ret = 0;
        for(int i=1; i<=N; i++){
            if(dist[i] <= T) ret++;
        }
        cout << ret << endl;

        if(cas) cout << endl;

        for(int i=0; i<=maxn; i++){
            G[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
