# include <bits/stdc++.h>
using namespace std;
# define int long long
int arr[100001];
int ans[100001];
signed main(){
    for(int i=0;i<100001;i++) ans[i]=1000000;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ans[0]=arr[0]; ans[1]=arr[1]; ans[2]=min(arr[2]+arr[0],arr[2]+arr[1]);
    for(int i=3;i<n;i++){
        ans[i]=arr[i]+min(min(ans[i-1],ans[i-2]),ans[i-3]);
    }
    if(n==3) cout<<min(arr[1],arr[0]+arr[2]);
    else if(n==2) cout<<min(arr[0],arr[1]);
    else if(n==1) cout<<arr[0];
    else cout<<min(ans[n-1],ans[n-2]);
    return 0;
}