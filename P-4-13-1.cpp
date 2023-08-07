#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[100001];
int ans = 0;
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t < 0)
            t = arr[i];
        else
            t = t + arr[i];
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}