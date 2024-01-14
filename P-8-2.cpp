# include <bits/stdc++.h>
using namespace std;
# define pii pair<int,int>

vector <pii> child[100010];  
int height[100010]={0},longest_dist[100010]={0};
void dfs(int v){  
    int h=0,dist=0;
    for(auto i : child[v]){
        int child=i.first;
        int weight=i.second;
        dfs(child);
        h=max(h,height[child]+1);
        dist=max(dist,longest_dist[child]+weight);
    }
    height[v]=h; longest_dist[v]=dist;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int parent,w;
        cin>>parent>>w;
        child[parent].push_back({i,w});    // store child and weight
    }
    dfs(0);
    cout<<longest_dist[0]<<endl<<height[0]<<endl;
    return 0;
}