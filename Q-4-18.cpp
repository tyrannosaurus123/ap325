#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pq priority_queue<int, vector<int>, greater<int>>
#define io cin.tie(0), ios::sync_with_stdio(0)
int p[100010];
bool check(int k, int m, int n)
{
    pq counter;
    int maxn = -1;
    for (int i = 0; i < k; i++)
    {
        counter.push(p[i]);
        maxn = max(maxn, p[i]);
    }
    for (int i = k; i < m; i++)
    {
        int l = counter.top();
        counter.pop();
        counter.push(l + p[i]);
        maxn = max(maxn, l + p[i]);
    }
    return maxn <= n;
}
signed main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    int left = 0, right = m;
    int ans;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (check(mid, m, n))
        {
            right = mid;
            ans = mid;
        }
        else
            left = mid + 1;
    }
    cout << ans << endl;
    return 0;
}