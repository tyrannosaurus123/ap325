#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void rec(vector<ll> &v, int i, ll prod, map<ll, ll> &m, ll p)
{
    if (i == v.size())
    {
        m[prod]++;
        return;
    }
    rec(v, i + 1, (prod * v[i]) % p, m, p);
    rec(v, i + 1, prod, m, p);
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
    int i, n;
    vector<ll> a, b;
    ll p;
    scanf("%d %lld", &n, &p);
    ll len_a = n / 2, len_b = n - len_a;
    for (i = 0; i < len_a; i++)
    {
        ll t;
        scanf("%lld", &t);
        a.push_back(t);
    }
    for (int i = 0; i < len_b; i++)
    {
        ll t;
        scanf("%lld", &t);
        b.push_back(t);
    }
    map<ll, ll> m1, m2;
    rec(a, 0, 1, m1, p);
    rec(b, 0, 1, m2, p);
    m1[1]--, m2[1]--; // prod 傳入遞迴是1，必須扣掉
    ll ans = (m1[1] + m2[1]) % p;
    for (auto e : m1)
    {
        ll x = e.first, num = e.second;
        ll y = exp(x, p - 2, p);
        auto it = m2.find(y);
        if (it != m2.end())
            ans += num * (it->second);
    }
    printf("%lld\n", ans);
    return 0;
}