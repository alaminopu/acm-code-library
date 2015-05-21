#include <bits/stdc++.h>
#define maxn 101

using namespace std;

int m, n;
bool store[maxn][maxn];
bool Adj[maxn][maxn];

void dfs(int u, int v){
    if(Adj[u][v] == true) return;
    if(store[u][v] == false) return;
    Adj[u][v]= true;

    if(u+1<m){
        dfs(u+1,v);
    }
    if(u-1>=0){
        dfs(u-1, v);
    }
    if(v+1<n){
        dfs(u,v+1);
    }
    if(v-1>=0){
        dfs(u,v-1);
    }

    if(u+1<m && v+1<n){
        dfs(u+1, v+1);
    }
    if(u-1>=0 && v-1>=0){
        dfs(u-1, v-1);
    }
    if(u+1<m && v-1>=0){
        dfs(u+1, v-1);
    }
    if(u-1>=0 && v+1<n){
        dfs(u-1, v+1);
    }

}

int main(){
    char c;

    //freopen("input.txt","r", stdin);

    while(scanf("%d %d",&m, &n)==2){
        getchar();
        //cout << "M: " << m << " N: " << n << endl;
        if(m==0) break;

        memset(Adj,false,sizeof Adj);
        memset(store,false,sizeof store);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                c=getchar();
                if(c=='@'){
                    store[i][j]=true;
                }else{
                    store[i][j]=false;
                    Adj[i][j] = true;
                }
            }
            getchar();
        }

        int result=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!Adj[i][j]){
                    result++;
                    dfs(i,j);
                }
            }
        }

        cout << result << endl;


    }
    return 0;
}
