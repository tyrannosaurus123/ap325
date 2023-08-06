# include <bits/stdc++.h>
using namespace std;
# define int long long
# define pii pair<int,int>
int cmp(pii x,pii y){
    return x.second<y.second;
}
signed main(){
    int n;
    cin>>n;
    vector <pii> k;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        k.push_back({a,b});
    }
    sort(k.begin(),k.end(),cmp);
    int end=k[0].second;
    int ans=1;
    for(int i=1;i<n;i++){
        if(k[i].first>end){
            ans++;
            end=k[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}