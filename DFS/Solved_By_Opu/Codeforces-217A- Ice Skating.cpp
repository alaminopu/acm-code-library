#include <bits/stdc++.h>
#define maxn 105

using namespace std;

pair<int, int> sd[maxn];
int color[maxn];

void dfs(int n,int node){
    if(color[node]) return;
    color[node] = true;
    for(int i=1; i<=n; i++){
        if(sd[node].first == sd[i].first || sd[node].second == sd[i].second){
            dfs(n,i);
        }
    }
}

int main(){
    int n,x,y;
    //freopen("input.txt","r", stdin);

    while(cin >> n){
        memset(color,false,sizeof color);

        for(int i=1; i<=n; i++){
            cin>>x>>y;
            sd[i]=make_pair(x,y);
        }

        int ret = 0;
        for(int i=1; i<=n; i++){
            if(!color[i]){
                ++ret;
                dfs(n, i);
            }
        }

        cout << ret-1 << endl;
    }

    return 0;
}
