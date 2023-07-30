#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Maxn 1e18 + 1
#define io ios::sync_with_stdio(0);
const int maxn = 1e5 + 5;
int c[maxn];
int h[maxn];
signed main()
{
    io 
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
    while (1)
    {
        int i;
        int flag = 0;
        for (i = 1; i <= m; i++)
        {
            if (h[i] == 0)
                continue;
            int prev = i - 1;
            int next = i + 1;
            while (h[prev] == 0)      // 左半邊已經砍的樹
                prev--;
            while (h[next] == 0)      // 右半邊已經砍的樹
                next++;
            if (c[i] - h[i] >= c[prev] || c[i] + h[i] <= c[next])
            {
                total++;
                if (h[i] > high)
                    high = h[i];
                h[i] = 0;        // 把可以砍的樹設為 0
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    cout << total << endl << high;
    return 0;
}