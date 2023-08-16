# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0)
# define pii pair<int,int>
bool cmp(pii t1,pii t2){
    if(t1.first==t2.first) return t1.second<t2.second;
    return t1.first<t2.first;
}
signed main(){
    io;
    int n,start,end;
    cin>>n>>start>>end;
    vector <pii> k;
    stack <pii> q;
    for(int i=0;i<n;i++){
        int s1,e1;
        cin>>s1>>e1;
        k.push_back({s1,e1});
    }
    sort(k.begin(),k.end(),cmp);
    int s=-1,e=-1,pos=n;           // if not find , pos=n , it won't execute next for loop
    for(int i=0;i<n;i++){          // First , find the "best" start time
        if(k[i].first<=start && k[i].second>start){
            if(q.empty()){
                pos=i+1;
                s=k[i].first;
                e=k[i].second;
                q.push(k[i]);
            }
            else if(k[i].second>e){
                q.pop();
                s=k[i].first;
                e=k[i].second;
                pos=i+1;
                q.push(k[i]);
            }
        }
        else if(k[i].first > start) break;
    }
    for(int i=pos;i<n;i++){
        int e1=q.top().second;
        if(k[i].first>e1 || e>=end) break;
        if(k[i].second<=e1) continue;
        q.push(k[i]);
        e=k[i].second;
        while(i++){                    // find better time, 
            int e2=q.top().second;    //e.g. [0,2],[1,3],[2,4] -> [2,4] is better than [1,3]
            if(k[i].first <= e1){
                if(k[i].second > e2){
                    q.pop();
                    q.push(k[i]);
                    e=k[i].second;
                }
            }
            else{
                i--;
                break;
            }
        }
    }
    if(s<=start && e>=end) cout<<q.size()<<endl;
    else cout<<-1<<endl;
    return 0;
}