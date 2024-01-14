// P-8-3 tree median, dfs method, O(n)
# include <bits/stdc++.h>
using namespace std;
# define N 100010
# define int long long

vector<pair<int,int>> child[N];
int n, num[N]={0}, median=-1, total=0;

void dfs(int v) {
    for (auto e: child[v]) {
        int u=e.first, w=e.second;
        dfs(u);
        total += min(num[u], n-num[u]) * w;
        num[v] += num[u];
    }
    num[v]++; // add itself
    if (median<0 && num[v]>=n/2){
        median = v;
    }
    return;
}

signed main() {
    cin>>n;
    for (int i=1;i<n;i++) {
        int v, w;
        cin>>v>>w;
        child[v].push_back({i,w});
    }
    dfs(0);
    cout<<median<<endl<<total<<endl;
    return 0;
}