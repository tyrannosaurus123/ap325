#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0)

int ToInt(string s, int p)
{                               
    int res = (s[0] - '0') % p;         // 123%p=((((1%p)*10+2)%p)*10+3)%p
    for (int i = 1; i < s.size(); i++)
    {
        res = (res * 10 + (s[i] - '0')) % p;
    }
    return res;
}
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
    io;
    int n, p;
    string s;
    cin >> s >> n >> p;
    cout << fastpow(ToInt(s, p), n, p);
    return 0;
}