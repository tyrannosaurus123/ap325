# include <bits/stdc++.h>
using namespace std;
# define int long long

signed main(){
    int n;
    cin>>n;
    vector <int> k;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        k.push_back(t);
    }
    int ans[n];
    ans[0]=k[0]; ans[1]=max(k[1],k[0]);
    for(int i=2;i<n;i++){
        ans[i]=max(ans[i-1],ans[i-2]+k[i]);
    }
    cout<<ans[n-1]<<endl;
    return 0;
}