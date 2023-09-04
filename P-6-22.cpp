# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 100010
struct member{
    int p,c,m;
} seq[N];
bool cmp(member x,member y){
    if(x.c==y.c) return x.m<y.m;
    return x.c>y.c;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>seq[i].p;
    }
    for(int i=0;i<n;i++){
        cin>>seq[i].c;
    }
    for(int i=0;i<n;i++){
        cin>>seq[i].m;
    }
    sort(seq,seq+n,cmp);
    int ans=0;
    map <int,int> M;   //{m,p} largest p with ending m
    M.insert({-1,0});  // as a boundary
    for(int i=0;i<n;i++){
        auto it=M.upper_bound(seq[i].m);
        it--;    // it.m is equal or smaller than seq[i].m
        int w=seq[i].p+it->second;
        ans=max(ans,w);
        it=M.insert(it,{seq[i].m,w});  // insert {seq[i].m,w} in it position
        if(it->second<w){         // if {seq[i].m,w} already in M , the upper code won't do anything
            it->second=w;
        }
        it++;
        while(it!=M.end() && it->second<=w){
            it=M.erase(it);     // return the next element
        }
    }
    cout<<ans<<endl;
    return 0;
}