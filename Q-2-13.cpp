#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ansx = 0, ansy = 0;
ll p = 1e9 + 9;
void fastpow(ll x, ll y, ll n)
{
    if (n == 1)
    {
        ansx = x % p;
        ansy = y % p;
        return;
    }
    else if (n & 1)
    {
        fastpow(x, y, n - 1);
        ll tmp = ansx;
        ansx = (x * ansx + y * ansy * 2) % p;
        ansy = (x * ansy + y * tmp) % p;
        return;
    }
    fastpow(x, y, n / 2);
    ll tmp = ansx;
    ansx = ((ansx * ansx + ansy * ansy * 2) % p);
    ansy = (2 * tmp * ansy) % p;
    return;
}
int main()
{
    ll x, y, n;
    cin >> x >> y >> n;
    if (n == 0)
        cout << 1 << " " << 0 << endl;
    else
    {
        fastpow(x, y, n);
        cout << ansx << " " << ansy << endl;
    }
    return 0;
}