#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0)
typedef long long ll;
int main()
{
    io;
    ll n, cnt = 0;
    set<ll> k;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        if (!k.count(m))
        {
            k.insert(m);
            a[cnt++] = m;
        }
    }
    sort(a, a + cnt);
    cout << cnt << endl;
    for (int i = 0; i < cnt - 1; i++)
        cout << a[i] << " ";
    cout << a[cnt - 1];
    return 0;
}