#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int i, n;
    ll p, a[50];
    scanf("%d %lld", &n, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    map<ll, ll> m1;        // (product, number)
    m1[a[0]] = 1;          // The first element appear once
    for (i = 1; i < n; i++)
    {
        map<ll, ll> m2(m1);         // copy M1 to M2
        for (auto e : m1)
        {
            ll t = (e.first * a[i]) % p;
            m2[t] = (m2[t] + e.second) % p;
        }
        m2[a[i]] = (m2[a[i]] + 1) % p;
        m1.swap(m2);
    }
    printf("%lld", m1[1]);
    return 0;
}