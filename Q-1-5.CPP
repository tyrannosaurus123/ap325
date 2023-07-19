#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
ll rec = 0;
ll black(ll pos, ll n)
{
    if (s[pos] == '0')
        return 0;
    else if (s[pos] == '1')
        return n * n;
    else
    {
        ll ans = 0;
        ans += black(++rec, n / 2);
        ans += black(++rec, n / 2);
        ans += black(++rec, n / 2);
        ans += black(++rec, n / 2);
        return ans;
    }
}
int main()
{
    cin >> s;
    ll n;
    cin >> n;
    cout << black(0, n);
    return 0;
}