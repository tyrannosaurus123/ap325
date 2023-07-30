# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0);
signed main(){
    io
    int m,n;
    cin>>m>>n;
    int ans=0;
    deque <int> k;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        k.push_back(t);
    }
    while(m>=n){
        int maxn=0,minn=1e9+9;
        for(int i=0;i<n;i++){
            minn=min(minn,k[i]);
            maxn=max(maxn,k[i]);
        }
        ans=max(ans,maxn-minn);
        k.pop_front();
        m--;
    }
    cout<<ans<<endl;
    return 0;
}