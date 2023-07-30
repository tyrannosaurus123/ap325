# include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int m,n;
    cin>>m>>n;
    vector <int> k;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        k.push_back(t);
    }
    int left=0,right,sum=0,ans=0,num=0;
    for(right=0;right<m;right++){
        sum+=k[right];
        while(sum>n){
            sum-=k[left];
            left++;
        }
        if(sum>ans){
            ans=sum;
            num=1;
        }
        else if(ans==sum) num++;
    }
    cout<<ans<<endl<<num<<endl;
    return 0;
}