#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define io cin.tie(0), ios::sync_with_stdio(0);
ll sa[1 << 19], sb[1 << 19]; // subset product of a and b
ll num[1 << 19], len_sb2 = 1;
int subset(ll v[], int len, ll prod[], ll p)
{
    int k = 0; // size of prod
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < k; j++)
        { // each subset*v[i]
            prod[k + j] = (prod[j] * v[i]) % p;
        }
        prod[k + k] = v[i]; // for subset v[i]
        k = k * 2 + 1;
    }
    return k;
}
ll exp(ll x, ll y, ll p)
{
    if (y == 0)
        return 1;
    if (y & 1)
        return (x * exp(x, y - 1, p)) % p;
    ll t = exp(x, y / 2, p);
    return (t * t) % p;
}
int main()
{
    io int i, n;
    ll a[30], b[30];
    ll p;
    scanf("%d %lld", &n, &p);
    int alen = n / 2;
    int blen = n - n / 2;
    for (i = 0; i < alen; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < blen; i++)
    {
        scanf("%lld", &b[i]);
    }
    int len_sa = subset(a, alen, sa, p);
    int len_sb = subset(b, blen, sb, p);
    sort(sb, sb + len_sb);
    num[0] = 1;
    for (int i = 1; i < len_sb; i++)
    {
        if (sb[i] != sb[i - 1])
        {
            sb[len_sb2] = sb[i]; // 把不重複的值傳回sb
            num[len_sb2] = 1;
            len_sb2++;
        }
        else
        {
            num[len_sb2 - 1]++;
        }
    }
    // 因為題目說所有數皆為正整數，所以sb[0]一定大於等於1
    ll ans = (sb[0] == 1) ? num[0] % p : 0; // 如果 sb[0]==1，ans=sb[0] (sb陣列所有組合 mod p為1)
    for (int i = 0; i < len_sa; i++)
    {
        if (sa[i] == 1)
            ans = (ans + 1) % p;
        ll y = exp(sa[i], p - 2, p);
        int it = lower_bound(sb, sb + len_sb2, y) - sb;
        if (sb[it] == y)
            ans = (ans + num[it]) % p;
    }
    printf("%lld\n", ans);
    return 0;
}