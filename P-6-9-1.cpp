# include <bits/stdc++.h>
using namespace std;
int ans[100001]={0};
signed main(){
    int m,n;
    int w[101];
    int v[101];
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        cin>>v[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=n-w[i];j>=0;j--){
            if(ans[j]+v[i]>ans[j+w[i]]){
                ans[j+w[i]]=ans[j]+v[i];
            }
        }
    }
    cout<<ans[n]<<endl;
    return 0;
}