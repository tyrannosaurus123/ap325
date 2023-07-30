#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int m, n;
    cin >> m >> n;
    set<int> s{0};
    int sum = 0, ans = 0;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        sum += t;
        int it = *s.lower_bound(sum - n);
        if (sum - it > ans && sum - it <= n)
            ans = sum - it;
        s.insert(sum);
    }
    cout << ans << endl;
    return 0;
}