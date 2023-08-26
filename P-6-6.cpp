#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[201][201] = {0};
int ans[201][201] = {0};
signed main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            ans[i][j] = -1000000;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                ans[i][j] = arr[i][j];
            else
                ans[i][j] = arr[i][j] + max(ans[i][j - 1], ans[i - 1][j]);
        }
    }
    cout << ans[m][n];
    return 0;
}