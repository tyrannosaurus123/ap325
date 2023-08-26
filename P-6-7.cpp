# include <bits/stdc++.h>
using namespace std;
# define int long long

int ans[501][501]={0};
signed main(){
    string s1,s2;
    cin>>s1>>s2;
    int len1=s1.size();
    int len2=s2.size();
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s2[j-1]==s1[i-1]) ans[i][j]=ans[i-1][j-1]+1;
            else ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
        }
    }
    cout<<ans[len1][len2]<<endl;
    return 0;
}