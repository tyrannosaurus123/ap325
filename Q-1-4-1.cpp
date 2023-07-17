#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);
using ll = long long;
ll arr[50010]; // arr為左閉右開
ll rec(int left, int right, int time)
{
    if (time == 0 || right - left <= 2)
        return 0;
    ll ans = 2e18, pos = 0;
    for (int i = left + 1; i < right - 1; i++)
    { // 線性搜尋
        ll ltmp = 0, rtmp = 0, flag = 1;
        for (int j = left; j < right; j++)
        {
            if (i == j)
                flag = 0;
            if (flag)
                ltmp += abs(arr[j] * (i - j));
            else
                rtmp += abs(arr[j] * (i - j));
        }
        ll result = abs(ltmp - rtmp);
        if (ans > result)
        {
            pos = i;
            ans = result;
        }
    }
    return arr[pos] + rec(left, pos, time - 1) + rec(pos + 1, right, time - 1);
}
int main()
{
    io;
    ll m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    cout << rec(0, m, n);
    return 0;
}