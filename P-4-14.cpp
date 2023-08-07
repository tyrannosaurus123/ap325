#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0)
#define pii pair<int, int>
bool cmp(pii p1, pii p2)
{
    if (p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first > p2.first;
}
signed main()
{
    io;
    int n;
    cin >> n;
    vector<pii> point;
    vector<int> x, y;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        x.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        y.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        point.push_back({x[i], y[i]});
    }
    sort(point.begin(), point.end(), cmp);
    int ans = 1;
    int ymax = point[0].second;
    for (int i = 1; i < n; i++)
    {
        int y1 = point[i].second;
        if (y1 > ymax)
        {
            ans++;
            ymax = y1;
        }
    }
    cout << ans << endl;
    return 0;
}