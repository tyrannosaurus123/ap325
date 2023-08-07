# include <bits/stdc++.h>
using namespace std;
# define int long long

signed main(){
    int n;
    cin>>n;
    int ans=0,buy=1e9+9;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        if(t<buy) buy=t;
        ans=max(ans,t-buy);
    }
    cout<<ans<<endl;
    return 0;
}