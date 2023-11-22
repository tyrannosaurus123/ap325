# include <bits/stdc++.h>
using namespace std;
# define pii pair<int,int>
int pool[510][510]={0};
int visited[510][510];
pii p[510][510];
int dir_i[4]={1,0,-1,0};
int dir_j[4]={0,1,0,-1};
pii find(int i,int j){
    if(p[i][j].first<0 && p[i][j].second<0) return {i,j};
    pii temp=find(p[i][j].first,p[i][j].second);
    p[i][j].first=temp.first;
    p[i][j].second=temp.second;
    return temp;
}
void bfs(int i,int j){
    queue <pii> q;
    q.push({i,j});
    visited[i][j]=1;
    while(!q.empty()){
        int i1=q.front().first;
        int j1=q.front().second;
        q.pop();
        // if(visited[i1][j1]){
        //     continue;
        // }
        visited[i1][j1]=1;
        for(int k=0;k<4;k++){
            int i2=i1+dir_i[k];
            int j2=j1+dir_j[k];
            if(pool[i2][j2] && !visited[i2][j2]){
                q.push({i2,j2});
                // visited[i2][j2]=1;
                p[i2][j2].first=i;
                p[i2][j2].second=j;
                p[i][j].first--;
            }
        }
    }
}
signed main(){
    int m,n,k;
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            p[i][j]={-1,-1};
            cin>>pool[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
    int ans1=0,ans2=0,largest=0,pool_num=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(pool[i][j] && !visited[i][j]){
                bfs(i,j);
                ans1=max(ans1,-p[i][j].first);
                ans2++;
            }
        }
    }
    largest=ans1;
    pool_num=ans2;
    for(int i=0;i<k;i++){
        int i1,j1,boss_i,boss_j;
        cin>>i1>>j1;
        boss_i=i1,boss_j=j1;
        pool[i1][j1]=1;
        for(int j=0;j<4;j++){
            if(pool[i1+dir_i[j]][j1+dir_j[j]]==0) continue;
            pii r2=find(i1+dir_i[j],j1+dir_j[j]);
            int i2=r2.first, j2=r2.second;
            if(boss_i==i2 && boss_j==j2) continue;
            pool_num--;
            if(p[boss_i][boss_j].first<p[i2][j2].first){
                p[boss_i][boss_j].first+=p[i2][j2].first;
                p[i2][j2].first=boss_i;
                p[i2][j2].second=boss_j;
                largest=max(largest,-p[boss_i][boss_j].first);
            }
            else{
                p[i2][j2].first+=p[boss_i][boss_j].first;
                p[boss_i][boss_j].first=i2;
                p[boss_i][boss_j].second=j2;
                largest=max(largest,-p[i2][j2].first);
                boss_i=i2; boss_j=j2;
            }
        }
        pool_num++;
        ans1+=largest;
        ans2+=pool_num;
        if(boss_i==i1 && boss_j==j1) continue;
        p[i1][j1].first=boss_i;
        p[i1][j1].second=boss_j;
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}