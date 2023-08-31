# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0)
signed main(){
    io;
    int n;
    cin>>n;
    vector <int> last;
    // last will be increasing
    int len=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        auto it=lower_bound(last.begin(),last.end(),t);
        if(it==last.end()) last.push_back(t);
        else *it=t;
    }
    cout<<last.size()<<endl;
    return 0;
}