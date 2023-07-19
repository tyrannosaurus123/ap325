using namespace std;
using ll=long long;
ll ans=0,n;
ll p;
ll k[26];
void rec(ll i,ll m){
    if(i>=n){
        if(m<=p && m>ans) ans=m;
        return;
    }
    rec(i+1,m+k[i]);
    rec(i+1,m);
    return ;
}
int main(){
    io;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    rec(0,0);
    cout<<ans<<endl;
    return 0;
}