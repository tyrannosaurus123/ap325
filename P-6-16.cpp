# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 100005
struct info{
    int s,t,e;
};
struct Operation{
    bool operator()(const info& a1,const info& a2) const{
        return a1.t<a2.t;
    }
};
bool cmp(info a1,info a2){
    return a1.t<a2.t;
}
signed main(){
    int n;
    cin>>n;
    int dp[N];
    vector <info> k;
    for(int i=1;i<=n;i++){
        int s1,t1,e1;
        cin>>s1>>t1>>e1;
        k.push_back({s1,t1,e1});
    }
    k.push_back({0,-1,0});
    sort(k.begin(),k.end(),cmp);
    dp[1]=k[1].e;
    for(int i=1;i<=n;i++){
        info tmp={0,k[i].s,0};
        Operation op;
        auto it=lower_bound(k.begin(),k.begin()+i,tmp,op);
        --it;
        dp[i]=k[i].e+dp[it-k.begin()];
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n]<<endl;
    return 0;
}