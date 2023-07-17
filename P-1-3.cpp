#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0)
using ll = long long;

vector<ll> k;
ll m, len;
ll rec(ll left, ll right)
{
    if (right - left <= 1)
        return 0;
    ll mid = (k[left] + k[right]) / 2;
    ll pos = lower_bound(k.begin() + left, k.begin() + right, mid) - k.begin();
    if (k[pos - 1] - k[left] >= k[right] - k[pos])
        pos--;
    return k[right] - k[left] + rec(left, pos) + rec(pos, right);
}
int main()
{
    io;
    cin >> m >> len;
    k.push_back(0);
    for (int i = 1; i <= m; i++)
    {
        ll n;
        cin >> n;
        k.push_back(n);
    }
    k.push_back(len);
    ll ans = rec(0, m + 1);
    cout << ans;
    return 0;
}