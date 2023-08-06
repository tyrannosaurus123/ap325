#include <bits/stdc++.h>
using namespace std;
#define int long long
int enemy[100001];
priority_queue<int> q;
bool cmp(int n, int m)
{
    return n > m;
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> enemy[i];
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        q.push(t);
    }
    int ans = 0;
    sort(enemy, enemy + n, cmp);
    for (int i = 0; i < n; i++)
    {
        int p = q.top();
        if (p > enemy[i])
        {
            q.pop();
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}