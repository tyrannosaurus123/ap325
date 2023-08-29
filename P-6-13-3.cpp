# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 200001
# define pq priority_queue

int n,k,c[N],dp[N];
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    pq <pair<int,int>> minq;
    dp[1]=c[1];
    minq.push({-dp[1],1});
    for(int i=2;i<=n;i++){
        if(i<=k+1){
            dp[i]=c[i];
        }
        else{
            while(minq.top().second<i-2*k-1){
                minq.pop();
            }
            dp[i]=-minq.top().first+c[i];
        }
        minq.push({-dp[i],i});
    }
    cout<<*min_element(dp+n-k,dp+n+1)<<endl;
    return 0;
}