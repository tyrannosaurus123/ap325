#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define io cin.tie(0), ios::sync_with_stdio(0);
deque<int> maxn, minn;
vector<pii> k;
void put_max(int i)
{
    while (!maxn.empty() && k[i].second > k[maxn.back()].second)
    {
        maxn.pop_back();
    }
    maxn.push_back(i);
}
void put_min(int i)
{
    while (!minn.empty() && k[i].second < k[minn.back()].second)
    {
        minn.pop_back();
    }
    minn.push_back(i);
}
signed main()
{
    io int m, n;
    cin >> m >> n;
    vector<int> x, y;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        x.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        y.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        k.push_back(make_pair(x[i], y[i]));
    }
    sort(k.begin(), k.end());
    int ans = 0;
    put_max(0);
    put_min(0);
    for (int i = 1; i < m; i++)
    {
        int tmp = llabs(k[i].first - k[maxn.front()].first);
        while (tmp > n)
        {
            maxn.pop_front();
            if (maxn.empty())
            {
                break;
            }
            tmp = llabs(k[i].first - k[maxn.front()].first);
        }
        tmp = llabs(k[i].first - k[minn.front()].first);
        while (tmp > n)
        {
            minn.pop_front();
            if (minn.empty())
            {
                break;
            }
            tmp = llabs(k[i].first - k[minn.front()].first);
        }
        put_max(i);
        put_min(i);
        ans = max(ans, k[maxn.front()].second - k[minn.front()].second);
    }
    cout << ans << endl;
    return 0;
}