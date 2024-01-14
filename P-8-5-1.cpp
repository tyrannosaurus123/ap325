# include <bits/stdc++.h>
using namespace std;
# define N 200020
vector <int> tree[N];
int node_weight[N]={0};
int stuff_weight[101]={0};

int dfs1(int node){
    if(tree[node].empty()){
        return node_weight[node];
    }
    node_weight[node]+=dfs1(tree[node][0]);
    node_weight[node]+=dfs1(tree[node][1]);
    return node_weight[node];
}
void dfs2(int node,int w){
    if(tree[node].empty()){
        node_weight[node]+=w;
        cout<<node<<" ";
        return ;
    }
    node_weight[node]+=w;
    int left_node=tree[node][0];
    int right_node=tree[node][1];
    if(node_weight[left_node]<=node_weight[right_node]){
        dfs2(left_node,w);
    }
    else{
        dfs2(right_node,w);
    }
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=n;i<2*n;i++){
        cin>>node_weight[i];
    }
    for(int i=0;i<m;i++){
        cin>>stuff_weight[i];
    }
    for(int i=0;i<n-1;i++){
        int parent,child1,child2;
        cin>>parent>>child1>>child2;
        tree[parent].push_back(child1);
        tree[parent].push_back(child2);
    }
    node_weight[1]=dfs1(1);
    for(int i=0;i<m;i++){
        dfs2(1,stuff_weight[i]);
    }
    return 0;
}