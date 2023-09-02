# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 300
# define Max 100000000
int p[N],memo[N][N];


signed main(){
    int n,l;
    cin>>n>>l;
    p[0]=0,p[n+1]=l;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n+1;i++){
        memo[i][i+1]=0;
    }
    for(int len=2;len<n+2;len++){
        for(int i=0;i+len<n+2;i++){     // cost(i, i+len)
            int j=i+len,mincost=Max;
            for(int k=i+1;k<j;k++){
                mincost=min(mincost,memo[i][k]+memo[k][j]);
            }
            mincost+=p[j]-p[i];
            memo[i][j]=mincost;
        }
    }
    cout<<memo[0][n+1]<<endl;
    return 0;
}