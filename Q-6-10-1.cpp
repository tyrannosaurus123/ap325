# include <bits/stdc++.h>
using namespace std;

int dp[101][200001]={0};
int p[101];
signed main(){
    int n,m,k,sum=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum+=p[i];
    }
    k=k-(m-sum);
    if(k<=0) cout<<0<<endl;
    else{
        for(int i=1;i<=200001;i++) dp[0][i]=2e5+5;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(p[i]<j){
                    int cmp=p[i]+dp[i-1][j-p[i]];
                    dp[i][j]=min(dp[i-1][j],cmp);
                }
                else{
                    dp[i][j]=min(p[i],dp[i-1][j]);
                }
            }
        }
        cout<<dp[n][k]<<endl;
    }
    return 0;
}