// 參考 https://cs.stackexchange.com/questions/160916/minimum-dominating-set-on-trees
# include <bits/stdc++.h>
using namespace std;
# define N 100010

vector <int> graph[N];
int dp_c[N]={0};  // answer for choosing the vertex
int dp_nc[N]={0}; // answer for may not choosing the vertex
int dp_min[N]={0};

void dfs(int v,int p){  // (current vertex , parent)
    int s=graph[v].size();
    if(s==0 || (s==1 && graph[v][0]==p)){   // v is leaf
        dp_c[v]=1;
        dp_min[v]=1;
        dp_nc[v]=0;
        return;
    }  

    for(int i : graph[v]){   // find every dp result of v's children
        if(dp_c[i]==0 && i!=p) dfs(i,v);
    }

    // choose the vertex
    dp_c[v]++;
    for(int i : graph[v]){
        if(i==p) continue;
        dp_c[v]+=dp_nc[i];
    }

    // may not choose the vertex
    int cmp=0;
    for(int i : graph[v]){    
        if(i==p) continue;  
        cmp+=dp_min[i];
    }
    dp_nc[v]=min(dp_c[v],cmp);

    // compare
    dp_min[v]=dp_c[v];
    for(int i : graph[v]){
        cmp=dp_c[i];
        if(i==p) continue;
        for(int j : graph[v]){
            if(i==j ||j==p) continue;
            cmp+=dp_min[j];
        }
        dp_min[v]=min(dp_min[v],cmp);
    }
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int s,t;
        cin>>s>>t;
        graph[t].push_back(s);
        graph[s].push_back(t);
    }
    dfs(1,0);
    cout<<dp_min[1]<<endl;
    return 0;
}