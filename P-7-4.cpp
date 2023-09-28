# include <bits/stdc++.h>
using namespace std;
# define N 510
# define Max 1000000
char a[N][N];
int dis[N][N];  // min distance (turn)
int di[4]={0,1,0,-1}, dj[4]={1,0,-1,0};
signed main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<=m+1;i++){
        a[i][0]=a[i][n+1]='1';
    }
    for(int j=0;j<=n+1;j++){
        a[0][j]=a[m+1][j]='1';
    }
    for(int i=1;i<=m;i++){
        scanf("%s",&a[i][1]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=-1;
        }
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    dis[1][1]=0;
    while(!q.empty() && dis[m][n]<0){
        auto p=q.front();
        q.pop();
        int si=p.first,sj=p.second;
        for(int dir=0;dir<4;dir++){
            int ni=si+di[dir], nj=sj+dj[dir];
            while(a[ni][nj]=='0'){     // until touch 1
                if (dis[ni][nj]==-1) { // not visited
                    dis[ni][nj]=dis[si][sj]+1;
                    q.push({ni,nj});
                }
                ni+=di[dir];
                nj+=dj[dir];
            }
        }
    }
    if (dis[m][n]>0) dis[m][n]--; // count one more
    printf("%d\n",dis[m][n]);
    return 0;
}