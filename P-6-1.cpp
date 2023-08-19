# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0);

signed main(){
    int n;
    cin>>n;
    int k[n+1],ans[n+1];
    for(int i=1;i<=n;i++) cin>>k[i];
    ans[0]=0; ans[1]=k[1];
    for(int i=2;i<=n;i++){
        ans[i]=min(ans[i-2]+k[i],ans[i-1]+k[i]);
    }
    cout<<ans[n]<<endl;
    return 0;
}