# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 1000010
int c[N],w[N];

int dp(int goal,int n){
    if(c[goal]>=0) return c[goal];
    int imax=0;
    for(int i=0;i<n;i++){
        if(goal & (1<<i)){
            imax=max(imax,dp(goal^(1<<i),n));
        }
    }
    c[goal]=imax+w[goal];
    return c[goal];
}
signed main(){
    int n;
    cin>>n;
    int m=1<<n;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=1;i<m;i++){
        c[i]=-1;
    }
    c[0]=w[0];
    cout<<dp(m-1,n)<<endl;
    return 0;
}