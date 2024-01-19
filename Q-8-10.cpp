// 參考 https://www.geeksforgeeks.org/vertex-cover-problem-dynamic-programming-solution-for-tree/
# include <bits/stdc++.h>
using namespace std;

vector <int> tree[100010];
int visited [100010]={0};
int vcover(int root){
    if(visited[root]!=0) return visited[root]; 
    if(tree[root].empty()){
        return visited[root]=0;
    }
    int ans1=1,ans2=0;
    for(int i : tree[root]){
        ans1+=vcover(i);
    }
    for(int i : tree[root]){
        ans2++;
        for(int j : tree[i]){
            ans2+=vcover(j);
        }
    }
    return visited[root]=min(ans2,ans1);
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int s;
        cin>>s;
        tree[s].push_back(i);
    }
    cout<<vcover(0)<<endl;
    return 0;
}