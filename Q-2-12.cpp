#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int k[100][10000] = {0};
ll psum[100][10000] = {0};
int main()
{
    ll ans = -1e9;
    ll p, m, n;
    cin >> p >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> k[i][j];
        }
    }
    for (int i = 1; i <= m; i++) // 每一行為前綴和
    {
        for (int j = 1; j <= n; j++)
        {
            psum[i][j] = psum[i - 1][j] + k[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            ll t = 0;
            set<int> s;
            for (int o = 1; o <= n; o++)
            {
                t += psum[j][o] - psum[i][o];
                auto it = s.lower_bound(t - p);
                if (it != s.end())
                {
                    ans = max(ans, t - *it);
                }
                s.insert(t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}