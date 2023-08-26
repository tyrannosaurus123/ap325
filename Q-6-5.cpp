# include <bits/stdc++.h>
using namespace std;
# define int long long
int psum[300][300];
signed main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>psum[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            psum[i][j]+=psum[i-1][j];
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<=m;j++){
            int tmp=0;
            for(int k=1;k<=n;k++){
                tmp+=psum[j][k]-psum[i][k];
                ans=max(tmp,ans);
                if(tmp<0) tmp=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}