# include <bits/stdc++.h>
using namespace std;
# define int long long
// 差分-1後取前綴max，就是不要減，但在後面本來要加的地方，還回來，如果後面沒有要加，就不必還
signed main(){
    int n;
    cin>>n;
    multiset <int> s;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        s.insert(l);
        auto it=s.upper_bound(r);
        if(it!=s.end()) s.erase(it);
    }
    cout<<s.size()<<endl;
    return 0;
}