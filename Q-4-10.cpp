#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0)
vector<int> game;
bool check(int f, int m, int n)
{
    int power = f;
    for (int i = 0; i < m; i++)
    {
        if (power < game[i])
        {
            if (n == 0)
            {
                return false;
            }
            else
            {
                power = f;
                n--;
            }
        }
        power -= game[i];
        if (power < 0)              // if f < p[i]
            return false;
    }
    return true;
}
signed main()
{
    io;
    int m, n, left = 0, right = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        right += t;
        game.push_back(t);
    }
    int ans;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (check(mid, m, n))
        {
            right = mid;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}