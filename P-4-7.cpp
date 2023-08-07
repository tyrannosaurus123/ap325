#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    int sum = 0;
    cin >> n;
    priority_queue<int> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        k.push(-t);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int m = k.top();
        k.pop();
        int t = k.top();
        k.pop();
        k.push(m + t);
        sum -= (m + t);
    }
    cout << -k.top() << endl
         << sum << endl;
    return 0;
}