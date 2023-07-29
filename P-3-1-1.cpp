#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);
using ll = long long;
ll ans = 0;
vector<ll> tree[100001];
ll dfs(int parent)
{
    ll height = 0;
    for (int i : tree[parent])
    {
        height = max(height, dfs(i));
    }
    ans += height;
    return height + 1;
}
signed main()
{
    io
    ll n;
    cin >> n;
    ll root = (1 + n) * n / 2;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int son;
            cin >> son;
            tree[i].push_back(son);
            root -= son;
        }
    }
    cout << root << endl;
    dfs(root);
    cout << ans << endl;
    return 0;
}