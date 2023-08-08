#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0)
struct group
{
    int p, s, t;
};
group k[100010];
bool cmp(group &g1, group &g2)
{
    return g1.s < g2.s;
}
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
    int ans = k[0].p;
    multimap<int, int> m; // { end time , people}
    m.insert({k[0].t, k[0].p});
    for (int i = 1; i < n; i++)
    {
        auto it = m.lower_bound(k[i].s);
        int tmp = k[i].p;
        while (it != m.end())
        {
            tmp += it->second;
            it++;
        }
        m.insert({k[i].t, k[i].p});
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}