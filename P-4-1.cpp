#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        int ans = 0;
        if (t >= 50)
        {
            ans += t / 50;
            t = t % 50;
        }
        if (t >= 10)
        {
            ans += t / 10;
            t = t % 10;
        }
        if (n >= 5)
        {
            ans += t / 5;
            t = t % 5;
        }
        ans += t;
        cout << ans << endl;
    }
    return 0;
}