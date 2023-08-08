#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0)
#define pii pair<int, int>
bool cmp(pii x, pii y)
{
    return x.second < y.second;
}
signed main()
{
    io;
    int n;
    cin >> n;
    vector<int> t, d;
    vector<pii> k;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int p;
            cin >> p;
            t.push_back(p);
        }
        for (int i = 0; i < m; i++)
        {
            int p;
            cin >> p;
            d.push_back(p);
        }
        for (int i = 0; i < m; i++)
        {
            k.push_back({t[i], d[i]});
        }
        sort(k.begin(), k.end(), cmp);
        int flag = 1;
        int time = 0;
        for (int i = 0; i < m; i++)
        {
            time += k[i].first;
            if (time > k[i].second)
            {
                flag = 0;
                break;
            }
        }
        k.clear();
        t.clear();
        d.clear();
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}