#include <bits/stdc++.h>
#define maxn 15
#define INF 99999999

using namespace std;

vector<int> G[maxn], cost[maxn];
int dist[maxn];
int p[maxn];

struct edge{
    int u;
    int w;
    edge(int a, int b){
        u = a;
        w = b;
    }

    bool operator < (const edge & that) const {
        return w > that.w;
    }
};

int dijkstra(int s, int e){
    for(int i=0; i<=maxn; i++){
        dist[i]= INF;
        p[i] = -1;
    }

    priority_queue<edge> q;
    q.push(edge(s,0));
    dist[s]=0;
    while(!q.empty()){
        edge top = q.top(); q.pop();
        int u = top.u;

        if(u == e) return dist[e];

        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            if(dist[u]+ cost[u][i] < dist[v]){
                dist[v] = dist[u] + cost[u][i];
                p[v] = u;
                q.push(edge(v,dist[v]));
            }
        }
    }

}

void print_path(int x){
    if(p[x] != -1){
        print_path(p[x]);
        printf(" ");
    }
    printf("%d",x);
}

int main(){
    //freopen("in.txt", "r", stdin);

    int N, M, x, y, ret, casno=0;
    while(cin >> N && N){
        for(int i=0; i<=maxn; i++){
            G[i].clear();
            cost[i].clear();
        }

        for(int i=1; i<=N; i++){
            cin >> M;
            for(int j=1; j<=M; j++){
                cin >> x >> y;
                G[i].push_back(x);
                //G[x].push_back(i);
                cost[i].push_back(y);
                //cost[x].push_back(y);
            }
        }
        int s, e;
        cin >> s >> e;
        ret = dijkstra(s, e);
        printf("Case %d: Path = ", ++casno);
        print_path(e);
        printf("; %d second delay\n", ret);
    }

}
