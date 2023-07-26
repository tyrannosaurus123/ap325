#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll m, n, sum = 0, ans = -1e9, v;
    set<ll> k{0};
    scanf("%lld %lld", &m, &n);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &v);
        sum += v;
        ll t = sum - n;
        auto it = k.lower_bound(t);
        if (it != k.end())
            ans = max(ans, sum - *it);
        k.insert(sum);
    }
    ans = max(ans, (ll)0);
    printf("%lld\n", ans);
    return 0;
}