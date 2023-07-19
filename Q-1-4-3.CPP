#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);
using ll = long long;
const int k = 50010;
ll arr[k]; // 左閉右開
ll front[k], back[k];
ll rec(int left, int right, int time)
{
    if (time == 0 || right - left < 3)
        return 0;
    ll pos, ans = 2e18, x = 0; // 設一個x變數，前綴和只需做1次
    front[left] = 0;
    for (int i = left + 1; i < right; i++)
    {
        x += arr[i - 1];
        front[i] = front[i - 1] + x;
    }
    x = 0;
    back[right - 1] = 0;
    for (int i = right - 2; i >= left; i--)
    {
        x += arr[i + 1];
        back[i] = back[i + 1] + x;
    }
    for (int i = left + 1; i < right - 1; i++)
    {
        ll tmp = abs(front[i] - back[i]); //  題目為 | Σ𝑝[𝑖]×(𝑖−𝑚) |，所以back裡的元素*(i-m) 一定小於0
        if (ans > tmp)
        {
            pos = i;
            ans = tmp;
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