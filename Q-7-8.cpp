# include <bits/stdc++.h>
using namespace std;
# define N 10001
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector <int> circle[n];
        int visit[n]={0};
        for(int j=0;j<m;j++){
            int s1,s2;
            cin>>s1>>s2;
            circle[s1].push_back(s2);
            circle[s2].push_back(s1);
        }
        int flag=1;
        for(int j=0;j<n;j++){
            if(visit[j]!=0) continue;
            queue <int> q;
            q.push(j);
            visit[j]=1;
            int is_push[n]={0};
            while(!q.empty()){
                int v=q.front();
                int color;
                if(visit[v]==1) color=2;
                else color=1;
                q.pop();
                for(int p=0;p<circle[v].size();p++){
                    int v1=circle[v][p];
                    if(visit[v1]!=0 && visit[v1]!=color){
                        flag=0;
                        break;
                    }
                    else if(!visit[v1] && !is_push[v1]){
                        visit[v1]=color;
                        is_push[v1]=1;
                        q.push(v1);
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}