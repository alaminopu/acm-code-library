#include <bits/stdc++.h>
#define maxn 50004
#define INF 99999999

using namespace std;

struct edge{
    int u;
    int w;
    edge(int a, int b){ u=a; w=b; }

    bool operator < (const edge &that) const{
        return w > that.w;
    }
};

vector<int> G[maxn], cost[maxn];
int dist[maxn];

int dijkstra(int s, int d){
    for(int i=0; i<maxn; i++){
        dist[i] = INF;
    }
    priority_queue<edge> q;
    q.push(edge(s,0));
    dist[s]=0;

    while(!q.empty()){
        edge top = q.top();
        int u = top.u;
        q.pop();

        if(u == d) return dist[d];

        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            if(dist[u]+cost[u][i] < dist[v]){
                dist[v] = dist[u]+cost[u][i];
                q.push(edge(v, dist[v]));
            }
        }

    }

    return -1;
}



int main(){
    //freopen("in.txt", "r", stdin);

    int n, m, s, t, testcase, x, y, w, ret, casno=0;
    cin >> testcase;
    for(int i=1; i<=testcase; i++){
        cin >> n >> m >> s >> t;

        for(int i=0; i<maxn; i++){
            G[i].clear();
            cost[i].clear();
        }

        for(int j=0; j<m; j++){
            cin >> x >> y >> w;
            G[x].push_back(y);
            G[y].push_back(x);
            cost[x].push_back(w);
            cost[y].push_back(w);
        }
        ret = dijkstra(s, t);
        if(ret == -1){
            printf("Case #%d: unreachable\n", ++casno);
        }else{
           printf("Case #%d: %d\n", ++casno, ret);
        }
    }


    return 0;
}
