#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0);
const int maxn = 1e9 + 10;
int h[1000000];
int chair[1000000];
signed main()
{
    io int n, ans = 0;
    cin >> n;
    h[0] = maxn;
    vector<int> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> chair[i];
    }
    k.push_back(1);
    int len = 0, index;   // len is length of k , index is position in K
    for (int i = 2; i <= n; i++)
    {
        index = len;      // for the start , index = len
        int tmp = h[i] + chair[i];
        while (1)
        {
            if (k.empty() || index == -1)
            {
                ans += i - 1;
                k.push_back(i);
                len++;
                break;
            }
            else if (h[k[index]] <= tmp)
            {
                if (h[k[len]] < h[i])
                {
                    k.pop_back();
                    len--;
                }
                index--;
            }
            else
            {
                k.push_back(i);
                len++;
                ans += i - k[index] - 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}