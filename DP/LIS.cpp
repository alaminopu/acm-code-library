#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int dp[maxn];
int A[maxn];

void LIS(int n){
    for(int i=1; i<=n; i++){
        dp[i]=1;
        for(int j=i-1; j>=1;j--){
            if(A[i]<=A[j]) continue;
            dp[i]= max(dp[i], 1+dp[j]);
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    memset(dp, 0, sizeof dp);
    int n;
    cin >>n;
    for(int i=1; i<=n; i++){
        cin >>A[i];
        //cout << A[i] << endl;
    }
    LIS(n);
    int ret= *max_element(dp+1, dp+n+1);
    cout << ret << endl;

    return 0;
}
