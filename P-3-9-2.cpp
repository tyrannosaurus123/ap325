# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0);
# define N 2000010
int color[N]={0};
int k[N];
signed main(){
    io
    int n,l,cnt=0;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    for(int i=0;i<l;i++){
        color[k[i]]++;
        if(color[k[i]]==1) cnt++;
    }
    int ans=cnt;
    for(int i=l,left=0;i<n;i++,left++){
        color[k[i]]++;
        if(color[k[i]]==1) cnt++;
        color[k[left]]--;
        if(color[k[left]]==0) cnt--;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}