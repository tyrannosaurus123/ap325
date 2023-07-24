#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);

int k[14][14];
int rec(int up, int down, int left, int right)
{
    if (up == down || left == right)
        return 0;
    int ans = 1e9, one = 0, zero = 0;
    // take up
    for (int i = left; i <= right; i++)
    {
        if (k[up][i] == 1)
            one++;
        else if (k[up][i] == 0)
            zero++;
    }
    int tmp = min(one, zero);
    tmp += rec(up + 1, down, left, right);
    ans = min(ans, tmp);
    one = 0, zero = 0;
    // take left
    for (int i = up; i <= down; i++)
    {
        if (k[i][left] == 1)
            one++;
        else if (k[i][left] == 0)
            zero++;
    }
    tmp = min(one, zero);
    tmp += rec(up, down, left + 1, right);
    ans = min(ans, tmp);
    one = 0, zero = 0;
    // take down
    for (int i = left; i <= right; i++)
    {
        if (k[down][i] == 1)
            one++;
        else if (k[down][i] == 0)
            zero++;
    }
    tmp = min(one, zero);
    tmp += rec(up, down - 1, left, right);
    ans = min(ans, tmp);
    one = 0, zero = 0;
    // take right
    for (int i = up; i <= down; i++)
    {
        if (k[i][right] == 1)
            one++;
        else if (k[i][right] == 0)
            zero++;
    }
    tmp = min(one, zero);
    tmp += rec(up, down, left, right - 1);
    ans = min(ans, tmp);
    one = 0, zero = 0;
    return ans;
}
int main()
{
    io int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> k[i][j];
        }
    }
    cout << rec(1, m, 1, n);
    return 0;
}