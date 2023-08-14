#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define N 100010
#define io cin.tie(0), ios::sync_with_stdio(0)
signed main()
{
    io;
    vector<pii> point;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }
    sort(point.begin(), point.end());
    multimap<int, int> m;     // (y,x) sort by y
    int min_d = 1e9 + 9;      // min distacnce
    for (int i = 0; i < n; i++)
    {
        int x = point[i].first;
        int y = point[i].second;
        auto it = m.lower_bound(y - min_d);
        while (it != m.end() && it->first <= y + min_d)
        {
            if (x - it->second > min_d)
            {
                it = m.erase(it); // retrun the next postion of the removed element
                continue;
            }
            min_d = min(min_d, llabs(x - it->second) + llabs(y - it->first));
            it++;
        }
        m.insert({y, x});
    }
    cout << min_d << endl;
    return 0;
}