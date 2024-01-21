# include <bits/stdc++.h>
using namespace std;

vector <int> graph[100010];
int weight[100010];
int dp[100010]={0};
int visited[100010]={0};
int ans=0;

void dfs(int r){
    visited[r]=1;
    dp[r]=weight[r];
    for(int i : graph[r]){
        if(visited[i]) continue;
        dfs(i);
        dp[r]+=max(0,dp[i]);
    }
    ans=max(ans,dp[r]);
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n-1;i++){
        int s,t;
        cin>>s>>t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}