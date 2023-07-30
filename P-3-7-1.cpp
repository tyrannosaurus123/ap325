# include <bits/stdc++.h>
using namespace std;
# define int long long

signed main(){
    int n,k;
    int cnt=0,maxn=0,sum=0;
    cin>>n>>k;
    set <int> s{0};
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        sum+=t;
        auto it=s.lower_bound(sum-k);
        if(it!=s.end()){
            if(maxn<sum-*it){
                maxn=sum-*it;
                cnt=1;
            }
            else if(maxn==sum-*it) cnt++;
        }
        s.insert(sum);
    }
    cout<<maxn<<endl<<cnt<<endl;
    return 0;
}