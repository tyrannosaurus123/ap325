#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0);
const int maxn = 2e5 + 10;
int h[maxn], chair[maxn];
signed main()
{
    io int n, ans = 0;
    cin >> n;
    set<pair<int, int>> k; // height , position
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> chair[i];
    }
    k.insert({h[1], 1});
    for (int i = 2; i <= n; i++)
    {
        int tmp = chair[i] + h[i];
        auto it = k.upper_bound({tmp, i});
        if (it == k.end())
            ans += i - 1;
        else
        {
            int index = (*it).second;
            ans += i - index - 1;
        }
        while (!k.empty() && k.begin()->first <= h[i])
            k.erase(k.begin());
        k.insert({h[i], i});
    }
    cout << ans << endl;
    return 0;
}