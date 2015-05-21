#include <bits/stdc++.h>
#define maxn 105
using namespace std;

map<int, vector<int> > G;
map<int, int> dist;

void bfs(int source){
    int cnt = 0;
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<G[u].size(); ++i){
            int v = G[u][i];
            if(!dist.count(v)){
                dist[v]= dist[u]+1;
                q.push(v);
            }
        }
    }

    //return cnt;

}

int main(){
    int n, x, y, cas=0;
    //freopen("input.txt", "r", stdin);

    while(cin >> n){
        if(n==0) break;

        G.clear();

        for(int i=0; i<n; i++){
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int source, ttl;
        while(cin >> source >> ttl){
            if(source == 0 && ttl == 0) break;
            dist.clear();
            bfs(source);

            int ret = 0;
            map<int, int>::iterator it;
            for(it=dist.begin(); it!=dist.end(); ++it){
                if((*it).second>ttl) ret++;
            }

            ret = ret + (G.size() - dist.size());
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cas,ret, source, ttl);
        }



    }

    return 0;
}
