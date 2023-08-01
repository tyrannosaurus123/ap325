#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[200001];
int dis[200001];
signed main()
{
    int m, n, ans = 0, cnt = 1;
    cin >> m >> n;
    vector<int> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        k.push_back(arr[i]);
    }
    sort(k.begin(), k.end());
    for (int i = 1; i < n; i++)
    {
        if (k[i] == k[i - 1])
            continue;
        else
            k[cnt++] = k[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(k.begin(), k.begin() + cnt, arr[i]) - k.begin();
    }
    deque<int> tmp;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (!len || dis[arr[i]] != 1)
        {
            tmp.push_back(arr[i]);
            dis[arr[i]] = 1;
            len++;
            if (len == m)
            {
                len--;
                ans++;
                dis[tmp[0]] = 0;
                tmp.pop_front();
            }
        }
        else
        {
            while (tmp[0] != arr[i])
            {
                dis[tmp[0]] = 0;
                len--;
                tmp.pop_front();
            }
            tmp.pop_front();
            tmp.push_back(arr[i]);
        }
    }
    cout << ans << endl;
    return 0;
}