// P-6-13 min cost of k-domination O(n), no STL
// p[i]= min cost to cover [1..i] and choosing i
// p[i] = c[i]+min{p[j]: j>i-2k-2}; and p[i]=c[i] for i<=k+1
# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 200005

int n,k,c[N],dp[N];
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int minq[N],head=0,tail=0;
    dp[1]=c[1];
    minq[tail++]=1;
    for(int i=2;i<=n;i++){
        if(i<=k+1){
            dp[i]=c[i];
        }
        else{
            if(minq[head]<i-2*k-1){
                head++;
            }
            dp[i]=dp[minq[head]]+c[i];
        }
        while(head<tail && dp[i]<=dp[minq[tail-1]]){
            tail--;
        }
        minq[tail++]=i;
    }
    int ans=dp[n-k];
    for(int i=n-k+1;i<=n;i++) ans=min(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}