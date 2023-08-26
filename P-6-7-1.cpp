# include <bits/stdc++.h>
using namespace std;
# define int long long

int ans[2][100001]={0};
signed main(){
    string s1,s2;
    cin>>s1>>s2;
    int len1=s1.size();
    int len2=s2.size();
    int from=0,to=1,tmp;
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s2[j-1]==s1[i-1]) ans[to][j]=ans[from][j-1]+1;
            else ans[to][j]=max(ans[from][j],ans[to][j-1]);
        }
        tmp=from; from=to; to=tmp;
    }
    cout<<ans[from][len2];
    return 0;
}