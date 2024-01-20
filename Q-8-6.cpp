# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 100010

vector<pair<int,int>> child[N];
int n, parent[N],num[N]={0}, total=0;

void dfs(int v) {
    for (auto e: child[v]) {
        int u=e.first, w=e.second;
        dfs(u);
        total += num[u]*(n-num[u])*w*2;
        num[v] += num[u];
    }
    num[v]++; // add itself
    return;
}

signed main(){
    cin>>n;
    for (int i=2;i<=n;i++) {
        cin>>parent[i];
    }
    for(int i=2;i<=n;i++){
        int weight;
        cin>>weight;
        child[parent[i]].push_back({i,weight});
    }
    dfs(1);
    cout<<total<<endl;
    return 0;
}