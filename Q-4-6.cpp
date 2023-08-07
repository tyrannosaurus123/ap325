#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
bool cmp(pii x, pii y)
{
    return (double)x.first / (double)x.second > (double)y.first / (double)y.second;
}
signed main()
{
    vector<int> w, f;
    vector<pii> k;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        w.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        f.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        k.push_back({w[i], f[i]});
    }
    sort(k.begin(), k.end(), cmp);
    int tmp = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += k[i].second * tmp;
        tmp += k[i].first;
    }
    cout << ans << endl;
    return 0;
}