// 參考 https://judge.tcirc.tw/ShowThread?postid=58&reply=0

#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);
using ll = long long;
ll arr[50010]; // arr為左閉右開
ll front[50010] = {0}, back[50010] = {0};
ll rec(int left, int right, int time)
{
    if (time == 0 || right - left < 3)
        return 0;
    ll pos, ans = 2e18;
    front[0] = arr[left];
    back[0] = arr[right - 1];
    for (int i = 1; i < right - left; i++)
    {
        front[i] = front[i - 1] + arr[i + left];    // 從前面做前綴和
        back[i] = back[i - 1] + arr[right - 1 - i]; // 從後面做後綴和
    }
    for (int i = 1; i < right - left; i++)
    { // 兩邊再做一次前、後綴和
        front[i] += front[i - 1];
        back[i] += back[i - 1];
    }
    for (int i = 1; i < right - left - 1; i++)
    {                                                            // 範圍是[s+1,t-1]
        ll tmp = abs(front[i - 1] - back[right - left - i - 2]); // back[right-left-1] = front [1] , -2是因為要找index的前一個位置
        if (ans > tmp)
        {
            ans = tmp;
            pos = i + left;
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