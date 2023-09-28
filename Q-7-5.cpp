# include <bits/stdc++.h>
using namespace std;
# define pii pair<int,int>

int visit[1000010]={0};
int a[1000010];
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,p,l,r;
    cin>>n>>p>>l>>r;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if (a[i] >= n || a[i] < 0) a[i] = n;
    }
    memset(visit, -1, sizeof(visit));
    queue <int> q;
    q.push(0);
    int flag=0;
    visit[0]=0;
    while(!q.empty() && visit[p]==-1){
        int now=q.front();
        q.pop();
        int nxt = now - l;
        if(nxt >= 0 && a[nxt] != n && visit[a[nxt]] == -1){
            visit[a[nxt]]=visit[now]+1;
            q.push(a[nxt]);
        }
        nxt = now + r;
        if(nxt < n && a[nxt] != n && visit[a[nxt]] == -1){
            visit[a[nxt]]=visit[now]+1;
            q.push(a[nxt]);
        }
    }
    cout<<visit[p]<<endl;
    return 0;
}