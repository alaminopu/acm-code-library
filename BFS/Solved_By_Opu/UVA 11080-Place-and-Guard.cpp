#include <bits/stdc++.h>
#define maxn 205

using namespace std;

vector<int> G[maxn];
int color[maxn];

int bfs(int node){
    int top, length, now;
    int visit=0, black = 0;
    queue<int> q;
    q.push(node);
    color[node] = 1;

    while(!q.empty()){
        top = q.front();
        q.pop();
        visit++;
        if(color[top]== 1) black++;

        length = G[top].size();
        for(int i=0; i<length; i++){
            now = G[top][i];
            //cout << "now " << endl;
            if(color[now] == -1){
                color[now] = 1-color[top];
                q.push(now);
            }else if(color[now] == color[top]){
                return -1;
            }
        }
    }

    if(visit==1) return 1;

    return min(black, visit-black);

}

int main(){
    int T, v,e, f, t;

    //freopen("input.txt", "r", stdin);

    scanf("%d",&T);
    while(T--){
        memset(color, -1, sizeof color);
        for(int i=0; i<maxn; i++){
            G[i].clear();
        }

        scanf("%d %d", &v, &e);

        for(int i=0; i<e; i++){
            cin >> f >> t;
            G[f].push_back(t);
            G[t].push_back(f);
        }


        bool flag = false;
        int ret=0;
        for(int i=0; i<v && !flag; i++){
            if(color[i] == -1){
                int temp = bfs(i);
                if(temp == -1) flag=true;
                else ret = ret + temp;
                //cout <<"ret: "<< ret << endl;
            }
        }

        if(flag) cout << "-1" << endl;
        else cout << ret << endl;
    }
    return 0;
}

