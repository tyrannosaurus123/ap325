#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
bool cmp(pii x, pii y)
{
    double a1 = (double)x.first / (double)x.second;
    double a2 = (double)y.first / (double)y.second;
    return a1 < a2;
}
signed main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> t, w;
    vector<pii> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        t.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        w.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        k.push_back({t[i], w[i]});
    }
    sort(k.begin(), k.end(), cmp);
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += k[i].first;
        ans += tmp * k[i].second;
    }
    cout << ans << endl;
    return 0;
}