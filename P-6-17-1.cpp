# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 300
# define Max 100000000
int p[N],memo[N][N];

int cost(int i,int j){
    if(memo[i][j]>=0) return memo[i][j];
    int mincost=Max;
    for(int k=i+1;k<j;k++){
        mincost=min(mincost,cost(i,k)+cost(k,j));
    }
    mincost+=p[j]-p[i];
    return memo[i][j]=mincost;
} 
signed main(){
    int n,l;
    cin>>n>>l;
    p[0]=0,p[n+1]=l;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n+2;i++){
        for(int j=i+1;j<n+2;j++){
            memo[i][j]=-1;
        }
    }
    for(int i=0;i<n+1;i++){
        memo[i][i+1]=0;
    }
    cout<<cost(0,n+1)<<endl;
    return 0;
}