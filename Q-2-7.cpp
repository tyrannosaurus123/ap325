#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, ans = 0;
    cin >> m >> n;
    map<int, int> k;
    int all = (1 << m) - 1;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            t = t | (1 << (s[j] - 'A')); // or
        }
        ans += k[t ^ all]; // xor
        k[t]++;
    }
    cout << ans;
    return 0;
}