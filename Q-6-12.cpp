# include <bits/stdc++.h>
using namespace std;
# define int long long

signed main(){
    int d[100005];
    int dp[100005];
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>d[i];
    }
    int maxn=0;
    for(int i=1;i<=n+1;i++){
        maxn=max(maxn,d[i]);
        dp[i]=maxn;
    }
    for(int i=n+2;i<=m;i++){
        int cmp=d[i]+dp[i-n-1];
        maxn=max(cmp,maxn);
        dp[i]=maxn;
    }
    cout<<maxn<<endl;
    return 0;
}