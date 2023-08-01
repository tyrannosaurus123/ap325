# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0);

int arr[2000001];
int tmp[2000001]={0};  
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans=0,cnt=0;
    deque <int> k;
    for(int i=1;i<=n;i++){
        if(tmp[arr[i]]==1){
            while(k[0]!=arr[i]){
                tmp[k[0]]=0;
                k.pop_front();
                cnt--;
            }
            k.pop_front();
            cnt--;
        }
        tmp[arr[i]]=1;
        k.push_back(arr[i]);
        cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}