# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0)
int rec(int arr[],int n){ 
    if(n==1) return arr[0];  
    else if(n==2){
        int maxn=max(arr[0],arr[1]);
        return max(maxn,min(arr[1],arr[0])*2);
    }   
    int mid=n/2;
    int ans=max(rec(arr,mid),rec(arr+mid,n-mid));
    int i=mid,j=mid,h=arr[mid];
    while(i>=0 || j<n){
        if(i<0) h=arr[j];
        else if(j>=n) h=arr[i];
        else h=max(arr[i],arr[j]);
        while(i>=0 && arr[i]>=h) i--;
        while(j<n && arr[j]>=h) j++;
        ans=max(ans,h*(j-i-1));
    }
    return ans;
}
signed main(){
    io;
    int n;
    cin>>n;
    int arr[100010];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec(arr,n);
    return 0;
}
