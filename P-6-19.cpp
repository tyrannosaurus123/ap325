# include <bits/stdc++.h>
using namespace std;
# define int long long

int dp[20][10];
signed main(){
    string n;
    cin>>n;
    int len=n.size();
    dp[1][0]=0;
    for(int i=1;i<=9;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=len;i++){
        dp[i][9]=1;
        for(int j=8;j>=0;j--){
            dp[i][j]=dp[i][j+1]+dp[i-1][j];
        }
    }
    int ans=0;
    for(int i=0;i<n[0]-'0';i++){
        ans+=dp[len][i];
    }
    int i;
    for(i=1;i<len;i++){
        int from=n[i-1]-'0';
        int to=n[i]-'0';
        if(to<from) break;
        for(int j=from;j<to;j++){
            ans+=dp[len-i][j];
        }
    }
    if(i==len) ans++;
    cout<<ans<<endl;
    return 0;
}