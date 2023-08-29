# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 200001

int n,k,c[N],dp[N];
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    deque <int> minq;
    dp[1]=c[1];
    minq.push_back(1);
    for(int i=2;i<=n;i++){
        if(i<=k+1){
            dp[i]=c[i];
        }
        else{
            if(minq.front()<i-2*k-1){
                minq.pop_front();
            }
            dp[i]=dp[minq.front()]+c[i];
        }
        while(!minq.empty() && dp[i]<=dp[minq.back()]){
            minq.pop_back();
        }
        minq.push_back(i);
    }
    cout<<*min_element(dp+n-k,dp+n)<<endl;
    return 0;
}