#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0)
int room[200010];

signed main()
{
    io;
    int m, n;
    cin >> m >> n;
    cin >> room[0];
    for (int i = 1; i < m; i++)
    {
        cin >> room[i];
        room[i] = room[i] + room[i - 1]; // prefix sum
    }
    int index = 0; // current room
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (index > 0)
            k = k + room[index - 1];
        if (k <= room[m - 1])
        {
            index = lower_bound(room + index, room + m, k) - room + 1;
        }
        else
        {
            k = k - room[m - 1];
            k = k % room[m - 1];
            index = lower_bound(room, room + m, k) - room + 1;
        }
    }
    cout << index << endl;
    return 0;
}