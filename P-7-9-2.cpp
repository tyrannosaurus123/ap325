#include <bits/stdc++.h>
using namespace std;
#define int long long
# define io cin.tie(0),ios::sync_with_stdio(0);
const int N=1e5+1;
int ans[N];
bool mark[N];              // dijkstra
vector <pair<int,int>> k[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, node_id}

void dijkstra(){
    while(!pq.empty()){
        auto p=pq.top(); pq.pop();
        int v=p.second;
        if(mark[v]) continue;
        for(auto [neighbor , weight] : k[v]){
            if(ans[neighbor]>ans[v]+weight){
                ans[neighbor]=ans[v]+weight;
                pq.push(make_pair(ans[neighbor], neighbor));
            }
        }
        mark[v]=true;
    }
}
signed main(){
    io
    for(int i=0;i<N;i++){
        ans[i]=1e18;
    }
    ans[0]=0;
    int n,m;
    cin>>n>>m;
    pq.push(make_pair(0,0));
    for(int i=0;i<m;i++){
        int v1,v2,dis;
        cin>>v1>>v2>>dis;
        k[v1].push_back({v2,dis});
        k[v2].push_back({v1,dis});
    }
    dijkstra();
    int maxn=-1,cnt=0;
    for(int i=0;i<n;i++){
        if(ans[i]==1e18) cnt++;
        else{
            maxn=max(maxn,ans[i]);
        }
    }
    cout<<maxn<<endl<<cnt<<endl;
    return 0;
}