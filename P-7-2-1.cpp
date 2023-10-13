# include <bits/stdc++.h>
using namespace std;
# define int long long
int value[50001];
int Visit[50001]={0};
vector <int> k[50001];
int dfs(int p){
    int sum=value[p];
    for(int i=0;i<k[p].size();i++){
        int p1=k[p][i];
        if(Visit[p1]) continue;
        Visit[p1]=1;
        sum+=dfs(p1);
    }
    return sum;
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        k[s].push_back(t);
        k[t].push_back(s);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(Visit[i]) continue;
        Visit[i]=1;
        ans=max(ans,dfs(i));
    }
    cout<<ans<<endl;
    return 0;
}