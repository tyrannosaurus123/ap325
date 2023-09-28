# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 102
# define Max 1000001
signed main(){
    int a[N][N];
    bool visit[N][N]={false};
    int di[4]={0,1,0,-1},dj[4]={1,0,-1,0};
    int i,j,n,m;
    cin>>m>>n;
    for(i=0;i<=m+1;i++){
        visit[i][0]=visit[i][n+1]=true;
    }
    for(j=0;j<=n+1;j++){
        visit[0][j]=visit[m+1][j]=true;
    }
    int si,sj,imax=Max;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]<imax){
                si=i, sj=j, imax=a[i][j];
            }
        }
    }
    int total=0;
    while(1){
        total+=a[si][sj];
        visit[si][sj] = true;
        imax=Max;
        for(int dir=0;dir<4;dir++){
            int ni=si+di[dir], nj=sj+dj[dir];
            if (!visit[ni][nj] && a[ni][nj] < imax){
                i=ni, j=nj, imax=a[ni][nj];
            }
        }
        if(imax==Max) break;
        si=i,sj=j;
    }
    cout<<total<<endl;
    return 0;
}