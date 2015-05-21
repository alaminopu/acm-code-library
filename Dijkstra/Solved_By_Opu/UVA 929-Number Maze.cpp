#include <bits/stdc++.h>
#define maxn 1005
#define INF 99999999

using namespace std;

struct edge{
    int r;
    int c;
    int w;

    edge(int _r, int _c, int _w){
        r = _r;
        c = _c;
        w = _w;
    }

    bool operator < (const edge & that) const{
        return w > that.w;
    }

};

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int grid[maxn][maxn], cost[maxn][maxn];
bool solved[maxn][maxn];
int N, M;

int dijkstra(int sr, int sc, int dr, int dc){
    priority_queue<edge> q;
    q.push(edge(sr, sc, grid[0][0]));
    cost[sr][sc] = grid[0][0];

    while(!q.empty()){
        edge top = q.top(); q.pop();

        if(solved[top.r][top.c]) continue;
        solved[top.r][top.c] = true;

        if(top.r == dr && top.c == dc) return cost[dr][dc];

        for(int i=0; i<4; i++){
            int u = top.r + dx[i];
            int v = top.c + dy[i];

            if(u>=0 && u<N && v>=0 && v<M && (cost[u][v]== -1 || cost[u][v] > cost[top.r][top.c] + grid[u][v])){
                cost[u][v] = cost[top.r][top.c] + grid[u][v];
                q.push(edge(u, v, cost[u][v]));
            }
        }

    }
}

int main(){
    //freopen("in.txt", "r", stdin);

    int T, ret;
    cin >> T;
    for(int k=1; k<=T; k++){
        cin >> N;
        cin >>  M;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> grid[i][j];
            }
        }

        for(int i=0; i<N; i++) fill(cost[i], cost[i]+M, -1);
        for(int i=0; i<N; i++) fill(solved[i], solved[i]+M, false);

        ret = dijkstra(0,0,N-1, M-1);

        cout << ret << endl;

    }


    return 0;
}

