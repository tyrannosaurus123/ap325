# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0);
vector <int> k;
deque <int> maxq,minq;
void put_max(int i){
    while(!maxq.empty() && k[maxq.back()]<=k[i]){
        maxq.pop_back();
    }
    maxq.push_back(i);
}
void put_min(int i){
    while(!minq.empty() && k[minq.back()]>=k[i]){
        minq.pop_back();
    }
    minq.push_back(i);
}
signed main(){
    io
    int m,n,ans=0;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        int t; cin>>t;
        k.push_back(t);
    }
    put_max(0);
    put_min(0);
    for(int i=1;i<m;i++){
        if(maxq.front()<=i-n){    // size of maxq must <= n
            maxq.pop_front();
        }
        if(minq.front()<=i-n){    // size of minq must <= n
            minq.pop_front();
        }
        put_max(i);
        put_min(i);
        ans=max(k[maxq.front()]-k[minq.front()],ans);
    }
    cout<<ans<<endl;
    return 0;
}