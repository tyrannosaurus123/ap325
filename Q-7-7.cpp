# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 10010
# define Max 10000001

int w[N];
int t[N];
int indeg[N]={0};
int maxd[N]={0};
int is_push[N]={0};
vector <int> track[N];
vector <int> root;
vector <int> k[N];
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        maxd[i]=t[i];
    }
    for(int i=1;i<=m;i++){
        int s,e;
        cin>>s>>e;
        k[s].push_back(e);
        indeg[e]++;
    }
    queue <int> q;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
            if(t[i]>ans){
                ans=t[i];
                root.clear();
                root.push_back(i);
            }
            else if(t[i]==ans){
                root.push_back(i);
            }
        }
    }
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<k[v].size();i++){
            int nxt=k[v][i];
            if(maxd[nxt]<maxd[v]+t[nxt]){
                maxd[nxt]=maxd[v]+t[nxt];
                track[nxt].clear();
                track[nxt].push_back(v);
                if(maxd[nxt]>ans){
                    ans=maxd[nxt];
                    root.clear();
                    root.push_back(nxt);
                }
                else if(maxd[nxt]==ans){
                    root.push_back(nxt);
                }
            }
            else if(maxd[nxt]==maxd[v]+t[nxt]){
                track[nxt].push_back(v);
            }
            if(--indeg[nxt]==0) q.push(nxt);
        }
    }
    cout<<ans<<endl;
    vector <int> ans_work;
    int len=0;
    for(int i=0;i<root.size();i++){
        int r=root[i];
        ans_work.push_back(r);
        len++;
        queue <int> tmp;
        tmp.push(r);
        while(!tmp.empty()){
            int now=tmp.front();
            for(int j=0;j<track[now].size();j++){
                if(!is_push[track[now][j]]){
                    is_push[track[now][j]]=1;
                    ans_work.push_back(track[now][j]);
                    len++;
                    tmp.push(track[now][j]);
                }
            }
            tmp.pop();
        }
    }
    sort(ans_work.begin(),ans_work.end());
    for(int i=0;i<len;i++) cout<<ans_work[i]<<" ";
    return 0;
}