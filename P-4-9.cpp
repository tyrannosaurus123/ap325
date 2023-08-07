#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> k;
int m, n;
bool check(int r, int p)
{
    int start = -1;
    for (int i = 0; i < m; i++)
    {
        if (start < k[i])
        {
            if (p > 0)
            {
                start = k[i] + r;
                p--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
signed main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        k.push_back(t);
    }
    sort(k.begin(), k.end());
    int r = k[m - 1], l = 0;
    int mid;
    int ans;
    while (l < r)
    {
        mid = (r + l) / 2;
        if (check(mid, n))
        {
            ans = mid;
            r = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}