#include <bits/stdc++.h>
#define maxn 200+5
using namespace std;

vector<int> v[maxn];
int color[maxn];

bool dfs(int node, int c){
    if(color[node]== 1-c) return false;
    if(color[node]==c) return true;
    color[node] =c ;
    bool ret = true;
    for(int i=0; i<v[node].size() && ret; i++){
        ret &= dfs(v[node][i], 1-c);
    }
    return ret;
}


int main(){
    int node, edge,x,y;
    //freopen("input.txt", "r", stdin);

    while(cin >> node >> edge){
        if(node==0) break;
        memset(color,-1,sizeof color);

        for(int i=0; i<maxn; i++){
            v[i].clear();
        }

        for(int i=0; i<edge; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int ret = dfs(0,0);

        if(ret) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;

    }

    return 0;
}
