# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0);
int rec(int arr[],int left,int right){
    if(right-left==1) return 0;
    else if(right-left==2){
        if(arr[left]>arr[right-1]) return 1;
        return 0;
    }
    int m=(left+right)/2;
    int sum=0;
    sum+=rec(arr,left,m);
    sum+=rec(arr,m,right);
    sort(arr+m,arr+right);
    for(int i=left;i<m;i++){
        int t=lower_bound(arr+m,arr+right,arr[i])-arr;
        sum+=t-m;
    }
    return sum;
}
int arr[100001];
signed main(){
    io;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec(arr,0,n);
    return 0;
}