# include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll pow(ll m,ll n,ll p){
    if(n==1) return m%p;
    if (n & 1) return (m*(pow(m,n-1,p)))%p;
    ll t=pow(m,n/2,p);
    return (t*t)%p;
}
int main(){
    ll n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        ll m;
        cin>>m;
        if(i==n-1) cout<<pow(m,p-2,p);
        else{
            if(p==2) cout<<1<<" ";
            else cout<<pow(m,p-2,p)<<" ";
        }
    }
    return 0;
}
