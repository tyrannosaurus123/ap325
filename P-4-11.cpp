#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
signed main()
{
    int n;
    cin >> n;
    vector<pii> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        k.push_back({a, b});
    }
    sort(k.begin(), k.end());
    int ans = 0;
    ans += k[0].second - k[0].first;
    int r = k[0].second;
    for (int i = 1; i < n; i++)
    {
        if (k[i].first >= r)
        {
            ans += k[i].second - k[i].first;
            r = k[i].second;
        }
        else if (k[i].second > r)
        {
            ans += k[i].second - r;
            r = k[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}