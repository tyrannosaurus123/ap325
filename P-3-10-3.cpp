#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define io cin.tie(0), ios::sync_with_stdio(0);
int cnt[N] = {0};

signed main()
{
    int n, sum = 0;
    map<int, int> m;
    vector<int> k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        k.push_back(t);
        m[t] = 0;
    }
    for (auto &p : m)       // map stores elements in a sorted order based on their keys. 
    {
        p.second = sum++;
    }
    int left = 0, ans = n, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        int index = m[k[i]];
        if (cnt[index] == 0)
        {
            tmp++;
        }
        cnt[index]++;
        index = m[k[left]];
        while (cnt[index] > 1)
        {
            cnt[index]--;
            index = m[k[++left]];
        }
        if (tmp == sum)
            ans = min(ans, i - left + 1);
    }
    cout << ans << endl;
    return 0;
}