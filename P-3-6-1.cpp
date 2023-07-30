#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Maxn 1e18 + 1
const int maxn = 1e5 + 5;
int c[maxn];
int h[maxn];
int rem(int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        if (c[i] - h[i] >= c[i - 1] || c[i] + h[i] <= c[i + 1])
        {
            return i;
        }
    }
    return -1;
}
signed main()
{
    int m, n;
    int total = 0, high = 0;
    cin >> m >> n;
    c[0] = 0;
    h[0] = Maxn;
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> h[i];
    }
    h[m + 1] = Maxn;
    c[m + 1] = n;
    m += 2;
    while (1)
    {
        int cut = rem(m);
        if (cut < 0)
            break;
        high = max(high, h[cut]);
        for (int i = cut; i < m - 1; i++)     // 找到可以刪除的點，把後面的往前搬
        {
            h[i] = h[i + 1];
        }
        for (int i = cut; i < m - 1; i++)
        {
            c[i] = c[i + 1];
        }
        total++;
        m--;
    }
    cout << total << endl << high;
    return 0;
}