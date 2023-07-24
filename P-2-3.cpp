#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0);

int fastpow(int m, int n, int p)
{
    if (n == 1)
        return m % p;
    else if (n & 1)
        return (m * fastpow(m, n - 1, p)) % p;
    else
    {
        int t = fastpow(m, n / 2, p) % p;
        return (t * t) % p;
    }
}
signed main()
{
    io int m, n, p;
    cin >> m >> n >> p;
    cout << fastpow(m, n, p);
    return 0;
}