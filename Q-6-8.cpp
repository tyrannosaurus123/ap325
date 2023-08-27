# include <bits/stdc++.h>
using namespace std;
# define int long long
int dp[501][501]={0};
signed main(){
    string s1,s2;
    cin>>s1>>s2;
    int len1=s1.size();
    int len2=s2.size();
    int ans=0;
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s2[j-1]==s1[i-1]){
                dp[i][j]=dp[i-1][j-1]+8;
                ans=max(ans,dp[i][j]);
            }
            else{
                int a=max(dp[i-1][j-1]-5,(int)0);
                int b=max(max(dp[i-1][j],dp[i][j-1])-3,(int)0);
                dp[i][j]=max(a,b);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}