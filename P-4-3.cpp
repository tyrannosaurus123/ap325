#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;
    vector<int> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        k.push_back(t);
    }
    sort(k.begin(), k.end());
    int ans = k[0];
    for (int i = 1; i < n; i++)
    {
        k[i] += k[i - 1];
        ans += k[i];
    }
    cout << ans << endl;
    return 0;
}