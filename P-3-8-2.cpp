# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0);

signed main(){
    io
    int m,n;
    cin>>m>>n;
    int ans=0;
    vector <int> k;
    set <int> s;
    int left=0,right=n;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        k.push_back(t);
        if(i<n) s.insert(t);
    }
    while(m>=n){
        int a=*s.begin();
        int b=*(--s.end());
        ans=max(b-a,ans);
        s.erase(k[left++]);
        s.insert(k[right++]);
        m--;
    }
    cout<<ans<<endl;
    return 0;
}
