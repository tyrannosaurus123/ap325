#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pq priority_queue<int, vector<int>, greater<int>> // from small to large
signed main()
{
    int m, n;
    cin >> m >> n;
    vector<int> k;
    pq p;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        k.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        p.push(k[i]);
    }
    for (int i = n; i < m; i++)
    {
        int t = p.top();
        p.push(t + k[i]);
        p.pop();
    }
    int ans;
    while (!p.empty())
    {
        ans = p.top();
        p.pop();
    }
    cout << ans << endl;
    return 0;
}