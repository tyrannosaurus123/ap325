# include <bits/stdc++.h>
using namespace std;
# define int long long 
# define  p 1000000009
int memo[101];

int cat(int n){
    if(memo[n]>=0) return memo[n];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=cat(i)*cat(n-i-1);
        sum%=p;
    }
    memo[n]=sum;
    return sum;
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        memo[i]=-1;
    }
    memo[0]=1;
    cout<<cat(n)<<endl;
    return 0;
}