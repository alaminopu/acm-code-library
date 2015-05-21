#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> edge[10000];

void bfs(){
    queue<int> Q;
    int taken[10000];
    for(int i=0; i<10000; i++) taken[i]=-1;
    Q.push(0);
    taken[0]=0;
    bool flag=true;

    while(!Q.empty() && flag){
        int u = Q.front();
       // printf("U: %d\n",u);
        Q.pop();
        int sizeu=edge[u].size();
        //printf("SizeU: %d\n",sizeu);
        for(int i=0; i<sizeu; i++){
            int v=edge[u][i];
           // printf("V: %d\n",v);
           // printf("TakenV: %d\n",taken[v]);
            if(taken[v]==-1){
                if(taken[u]==0){
                    taken[v]=1;
                }else{
                    taken[v]=0;
                }
            Q.push(v);
            }else{
                if(taken[v]==taken[u]){
                    flag= false;
                    break;
                }
            }
        }
    }

    if(flag){
        printf("BICOLORABLE.\n");
    }else{
        printf("NOT BICOLORABLE.\n");
    }

}

int main(){
    int n,e;
    int i,j;
    while(scanf("%d",&n) && n){
        scanf("%d",&e);

        for(j=0; j<10000; j++) edge[j].clear();

        for(i=0; i<e; i++){
            int x, y;
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        bfs();
    }
    return 0;
}
