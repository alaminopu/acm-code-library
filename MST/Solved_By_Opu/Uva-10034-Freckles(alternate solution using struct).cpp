#include <bits/stdc++.h>
#define maxn 10005
#define INF 99999999
using namespace std;

struct edge{
    int u;
    double w;
    edge(int a, double b){
        u = a;
        w = b;
    }
    bool operator < (const edge & that) const{
        return w > that.w;
    }
};

vector<int> G[maxn];
vector<double>cost[maxn];
double dist[maxn];
bool color[maxn];

double prims(){
    for(int i=0; i<maxn; i++){
        dist[i]=INF;
    }
    priority_queue<edge> q;
    q.push(edge(1,0));
    dist[1]=0;
    double ret=0;
    while(!q.empty()){
        edge top = q.top(); q.pop();
        int u = top.u;

        if(color[u]) continue;
        color[u] = true;
        ret += dist[u];

        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            if(!color[v] && cost[u][i] < dist[v]){
                //cout << cost[u][i] << endl;
                dist[v]=cost[u][i];
                q.push(edge(v,dist[v]));
            }
        }

    }
    return ret;

}


double calc(double a1, double b1, double a2, double b2){
    double result = (a1-a2)* (a1-a2) + (b1-b2)*(b1-b2);
    return sqrt(result);
}


int main(){
    //freopen("input.txt", "r", stdin);

    int T, n;
    double dist[maxn][2],c;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%lf %lf", &dist[i][0], &dist[i][1]);
        }

        for(int i=0; i<maxn; i++){
            G[i].clear();
            cost[i].clear();
        }
        memset(color, false, sizeof color);


        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                c = calc(dist[i][0], dist[i][1], dist[j][0], dist[j][1]);
                G[i].push_back(j);
                G[j].push_back(i);
                cost[i].push_back(c);
                cost[j].push_back(c);
            }
        }

        printf("%0.2lf\n", prims());

        if(T){
            puts("");
        }

    }
    return 0;
}

