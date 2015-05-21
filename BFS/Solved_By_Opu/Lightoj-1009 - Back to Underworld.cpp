#include <bits/stdc++.h>
#define maxn 20005

using namespace std;

vector<int> G[maxn];
bool color[maxn];
set<int> S;
set<int>::iterator it;


int bfs(int source){
    int cnt = 1, level_even=0, level_odd=0, status=1;
    queue<int> q,cq;
    q.push(source);
    color[source] = true;

    while(!q.empty()){
        if(cq.empty()){
            cq = q;
            if(status==1){
                level_odd += cnt;
                cnt=0;
                status=2;
            }else{
                level_even += cnt;
                cnt=0;
                status=1;
            }
        }
        int u = q.front();
        q.pop();
        cq.pop();

        for(int i=0; i<G[u].size(); ++i){
            int v = G[u][i];
            if(!color[v]){
                cnt++;
                color[v]=true;
                q.push(v);
            }
        }

    }

    return max(level_even, level_odd);
}

int main(){
    //freopen("input.txt", "r",stdin);
    //freopen("output.txt", "w", stdout);

    int T,casno = 0, n, u, v;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);

        for(int i=0;i<maxn; i++) G[i].clear();
        S.clear();
        memset(color, false, sizeof color);
        for(int i=0; i<n; i++){
            scanf("%d %d",&u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            S.insert(u);
            S.insert(v);
        }
        int result=0;

        for(it=S.begin(); it!=S.end(); ++it){
            if(!color[*it]){
                result+= bfs(*it);
            }
        }

        printf("Case %d: %d\n", ++casno, result);
    }

    return 0;
}
