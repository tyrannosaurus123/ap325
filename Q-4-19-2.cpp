#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0)
#define pq priority_queue

struct group
{
    int p, s, t;
};

group k[100010];

bool cmp(group &g1, group &g2)
{
    return g1.s < g2.s;
}

struct Operation
{
    bool operator()(const group &g1, const group &g2) 
    {
        return g1.t > g2.t;
    }
};

signed main()
{
    io;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i].p >> k[i].s >> k[i].t;
    }
    sort(k, k + n, cmp);
    pq<group, vector<group>, Operation> end1,end2; // compare by t
    int ans = k[0].p;
    end1.push(k[0]);
    for (int i = 1; i < n; i++)
    {
        int tmp=k[i].p,flag=1;
        while(!end1.empty()){
            flag=0;
            group g=end1.top();
            if(g.t>=k[i].s){
                end2.push(g);
                tmp+=g.p;
            }
            end1.pop();
        }
        if(flag){
            while(!end2.empty()){
                group g=end2.top();
                if(g.t>=k[i].s){
                    end1.push(g);
                    tmp+=g.p;
                }
                end2.pop();
            }
            end1.push(k[i]);
        }
        else end2.push(k[i]);
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}