# include <bits/stdc++.h>
using namespace std;
# define N 100001
int dp[101][N],p[N];
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=k;i++){
        int maxn=-p[1];
        for(int j=2;j<=n;j++){
            dp[i][j]=max(dp[i][j-1],maxn+p[j]);
            maxn=max(maxn,dp[i-1][j-1]-p[j]);
        }
    }
    cout<<dp[k][n]<<endl;
    return 0;
}