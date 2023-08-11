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
    pq<group, vector<group>, Operation> end1; // compare by t
    int ans = k[0].p, count=k[0].p;
    end1.push(k[0]);
    for (int i = 1; i < n; i++)
    {
        count+=k[i].p;
        group g=end1.top();
        while(g.t<k[i].s && !end1.empty()){
            if(k[i].s>g.t){
                count-=g.p;
                end1.pop();
            }
            g=end1.top();
        }
        end1.push(k[i]);
        ans=max(ans,count);
    }
    cout<<ans<<endl;
    return 0;
}