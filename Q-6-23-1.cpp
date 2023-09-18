# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 250000
signed main(){
    int n,p[N]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        int s,t,j;
        cin>>s>>t;
        for(j=s;j<=t;j++){
            p[j]++;
        }
        while(j<n && p[j]<p[j-1]){
            p[j]=p[j-1];
            j++;
        }
    }
    cout<<p[n-1]<<endl;
    return 0;
}