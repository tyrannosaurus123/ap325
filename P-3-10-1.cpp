#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define io cin.tie(0), ios::sync_with_stdio(0);
int r[N] = {0}, cnt[N] = {0};
signed main()
{
    io 
    int n, sum = 1, ans = 1e9 + 9, left = 0, tmp = 0;
    cin >> n;
    vector<int> k, c, d;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        k.push_back(t);
        d.push_back(t);
    }
    sort(d.begin(), d.end());
    c.push_back(d[0]);
    for (int i = 1; i < n; i++)
    {
        if (d[i] != d[i - 1])
        {
            c.push_back(d[i]);
            sum++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        r[i] = lower_bound(c.begin(), c.end(), k[i]) - c.begin();
    }
    for (int i = 0; i < n; i++)
    {
        int value = r[i];
        if (cnt[value] == 0)
        {
            tmp++;
        }
        cnt[value]++;
        while (cnt[r[left]] > 1)
        {
            cnt[r[left]]--;
            left++;
        }
        if (tmp == sum)
            ans = min(ans, i - left + 1);
    }
    cout << ans << endl;
    return 0;
}