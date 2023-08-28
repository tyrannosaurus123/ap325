# include <bits/stdc++.h>
using namespace std;
# define N 200001
int dp[2][N]={0};
int p[N];
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
        int from=0,to=1,tmp;
        for(int i=1;i<=N;i++) dp[0][i]=N;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(p[i]<j){
                    int cmp=p[i]+dp[from][j-p[i]];
                    dp[to][j]=min(dp[from][j],cmp);
                }
                else{
                    dp[to][j]=min(p[i],dp[from][j]);
                }
            }
            tmp=from; from=to; to=tmp;
        }
        cout<<dp[from][k]<<endl;
    }
    return 0;
}