#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define io cin.tie(0), ios::sync_with_stdio(0);
ll n, p;
ll ans = 0;
void rec(set<ll> &k, ll len, ll sum, ll m[], ll i)
{
    if (i == len)
    {
        if (!k.count(sum) && sum <= p)
            k.insert(sum);
        if (sum > ans && sum <= p)
            ans = sum;
        return;
    }
    rec(k, len, sum + m[i], m, i + 1);
    rec(k, len, sum, m, i + 1);
}
int main()
{
    scanf("%lld %lld", &n, &p);
    ll len_a = n / 2, len_b = n - len_a;
    ll a[20], b[20];
    for (int i = 0; i < len_a; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < len_b; i++)
    {
        scanf("%lld", &b[i]);
    }
    set<ll> a1, b1;
    rec(a1, len_a, 0, a, 0);
    rec(b1, len_b, 0, b, 0);
    for (ll i : a1)
    {
        ll t = p - i;
        auto s = b1.lower_bound(t);
        if (*s != t && s != b1.begin())
        {
            s--;
            ll cmp = *s + i;
            if (cmp > ans)
                ans = cmp;
        }
        else if (*s == t)
        {
            ans = p;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}