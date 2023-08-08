# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0)
# define pii pair<int,int>
signed main(){
    io;
    int n;
    cin>>n;
    vector <int> t,d;
    vector <pii> k;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        t.push_back(m);
    }
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        d.push_back(m);
    }
    for(int i=0;i<n;i++){
        k.push_back({t[i],d[i]});
    }
    sort(k.begin(),k.end());
    int ans=0;
    int time=0;
    for(int i=0;i<n;i++){
        time+=k[i].first;
        ans+=k[i].second-time;
    }
    cout<<ans<<endl;
    return 0;
}
