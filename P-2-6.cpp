#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define io cin.tie(0), ios::sync_with_stdio(0)

int main()
{
    io;
    ll alen,
    blen, k, ans = 0;
    cin >> alen >> blen >> k;
    ll a[alen], b[blen];
    for (int i = 0; i < alen; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < blen; i++)
    {
        cin >> b[i];
    }
    sort(b, b + blen);
    for (int i = 0; i < alen; i++)
    {
        ll index = k - a[i];
        int value = *lower_bound(b, b + blen, index);
        if (index == value)
            ans++;
    }
    cout << ans;
    return 0;
}