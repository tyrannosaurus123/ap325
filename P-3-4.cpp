#include <bits/stdc++.h>
using namespace std;
const int n = 2e5 + 5;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0);
int k[n];
signed main()
{
    io 
    int a;
    int ans = 1;
    cin >> a;
    stack<pair<int, int>> h; // height , position
    for (int i = 1; i <= a; i++)
    {
        cin >> k[i];
    }
    h.push({k[1], 1});
    for (int i = 2; i <= a; i++)
    {
        auto x = h.top();
        int value = x.first;
        int index = x.second;
        while (value <= k[i])
        {
            h.pop();
            if (h.empty())
            {
                ans += i;
                h.push(make_pair(k[i], i));
                break;
            }
            x = h.top();
            value = x.first;
            index = x.second;
        }
        if (value > k[i])
        {
            ans += i - index;
            h.push({k[i], i});
        }
    }
    cout << ans << endl;
    return 0;
}