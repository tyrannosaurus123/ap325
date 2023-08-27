# include <bits/stdc++.h>
using namespace std;
int ans[101][100005];
signed main(){
    int w[101],v[101];
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        cin>>v[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j-w[i]>=0){
                ans[i][j]=max(ans[i-1][j],v[i]+ans[i-1][j-w[i]]);
            }
            else{
                ans[i][j]=ans[i-1][j];
            }
        }
    }
    cout<<ans[m][n]<<endl;
    return 0;
}