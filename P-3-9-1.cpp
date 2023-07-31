#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0);
map<int, int> m;
signed main()
{
    io 
    int l, n;
    cin >> n >> l;
    vector<int> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        k.push_back(t);
    }
    for (int i = 0; i < l; i++)
    {
        auto it = m.find(k[i]);
        if (it != m.end())
        {
            it->second += 1;
        }
        else
            m[k[i]] = 1;
    }
    int ans = m.size();
    int left = 0, right = l;
    while (n > l)
    {
        auto it = m.find(k[left++]);
        if (it->second - 1 == 0)
            m.erase(it);
        else
            it->second--;
        it = m.find(k[right]);
        if (it != m.end())
            m[k[right]] += 1;
        else
            m[k[right]] = 1;
        right++;
        int cmp = m.size();
        ans = max(ans, cmp);
        n--;
    }
    cout << ans << endl;
    return 0;
}