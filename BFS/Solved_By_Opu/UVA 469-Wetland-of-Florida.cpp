#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int wland[maxn][maxn];
vector<string> grid;
int dirx[]={0, 0,1, 1,1,-1,-1,-1};
int diry[]={-1,1,-1,1,0,0,1,-1};
int n, m, counter;

void dfs(int i, int j){
    //cout << "i: "<< i << "j: " << j << endl;
    if(i<0 || i>=n || j<0 || j>=m || wland[i][j] == -1 || grid[i][j]=='L') return;
    wland[i][j] = -1;
    counter++;
    for(int k=0; k<8; k++){
        dfs(i+dirx[k], j+diry[k]);
    }

}

int main(){
    int cas,T;
    string s;

    //freopen("input.txt", "r", stdin);

    cin >> T;

    getline(cin,s); // capturing newline after cin
    getline(cin,s); // capturing newline before test case

    for(cas=1; cas<=T; cas++){
        grid.clear();

        while(1){
            getline(cin,s);
            if(s[0]!='W' && s[0]!='L') break;
            grid.push_back(s);
        }
        //cout << s << endl;

        n = grid.size(); // row
        m = grid[0].size(); // column

        //cout << n << " " << m << endl;

        memset(wland, 0, sizeof wland);

        counter=0;
        int row, column;
        istringstream is(s);
        is >> row >> column;
        dfs(row-1,column-1);
        cout << counter << endl;

        counter=0;
        while(getline(cin,s)){
            if(s.empty()) break;

            int row, column;
            istringstream is(s);
            is >> row >> column;

            memset(wland, 0, sizeof wland);
            dfs(row-1,column-1);
            cout << counter << endl;
            counter=0;
        }


        if(cas!=T){
            cout << endl;
        }
    }
    return 0;
}
