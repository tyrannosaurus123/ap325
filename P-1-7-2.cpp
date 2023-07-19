#include <bits/stdc++.h>
#define io cin.tie(0), ios::sync_with_stdio(0);
using namespace std;
using ll = long long;
ll ans = 0, n;
ll p = 10009;
ll k[26];
void rec(ll i, ll m)
{
    if (i >= n)
    {
        if (m == 1)
            ans++;
        return;
    }
    rec(i + 1, (m * k[i]) % p);
    rec(i + 1, m);
    return;
}
int main()
{
    io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    rec(0, 1);
    cout << ans - 1 << endl;
    return 0;
}