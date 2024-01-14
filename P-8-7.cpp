# include <bits/stdc++.h>
using namespace std;
# define N 200010

int n;
int ans=0;
int color[N];
int color_temp1[N];
int color_temp2[N];
int color_num[N]={0};
vector <int> tree[N];

void discrete(){
    int c=1;
    sort(color_temp1,color_temp1+n);
    color_temp2[0]=color_temp1[0];
    for(int i=1;i<n;i++){
        if(color_temp1[i]!=color_temp1[i-1]){
            color_temp2[c++]=color_temp1[i];
        }
    }
    for(int i=0;i<n;i++){
        color[i]=lower_bound(color_temp2,color_temp2+c,color[i])-color_temp2;
    }
}

void dfs(int node){
    color_num[color[node]]++;
    ans=max(ans,color_num[color[node]]);
    for(auto e : tree[node]){
        dfs(e);
    }
    color_num[color[node]]--;
}

signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>color[i];
        color_temp1[i]=color[i];
    }
    discrete();
    for(int i=0;i<n-1;i++){
        int s,t;
        cin>>s>>t;
        tree[s].push_back(t);
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}