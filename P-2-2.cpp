# include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int a;
    cin>>a;
    ll k[a];
    for(int i=0;i<a;i++){
        cin>>k[i];
    }
    vector <ll> m(k,k+a);      // copy k to m
    int cnt=0;
    sort(m.begin(),m.end());
    map <ll,int> t;
    t[m[0]]=0;
    for(int i=1;i<a;i++){
        if(t.find(m[i])!=t.end()) continue;
        else t[m[i]]=++cnt;
    }
    for(int i=0;i<a-1;i++){
        cout<<t[k[i]]<<" ";
    }
    cout<<t[k[a-1]]<<endl;
    return 0;
}