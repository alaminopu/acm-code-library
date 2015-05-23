#include <bits/stdc++.h>
#define maxn 10005
#define INF 99999999
using namespace std;

vector< pair<double, int> > G[maxn];
double cost[maxn];
bool color[maxn];

double prims(){
    for(int i=0; i<maxn; i++){
        cost[i]=INF;
    }
    priority_queue< pair<double, int> > q;
    q.push(make_pair(0,1));

    double ret=0;
    while(!q.empty()){
        int u = q.top().second;
        double c = q.top().first;
        q.pop();
        if(color[u]) continue;
        color[u] = true;
        ret -= c;
        cost[1]=0;
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i].second;
            double w = G[u][i].first;
            if(!color[v] && w < cost[v]){
                cost[v]= w;
                q.push(make_pair(-w, v));
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

        for(int i=0; i<maxn; i++) G[i].clear();
        memset(color, false, sizeof color);


        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                c = calc(dist[i][0], dist[i][1], dist[j][0], dist[j][1]);
                G[i].push_back(make_pair(c, j));
                G[j].push_back(make_pair(c, i));
            }
        }

        printf("%0.2lf\n", prims());

        if(T){
            puts("");
        }

    }
    return 0;
}

