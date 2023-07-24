#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0)

int main()
{
    io;
    int a;
    cin >> a;
    int k[a];
    for (int i = 0; i < a; i++)
    {
        cin >> k[i];
    }
    vector<int> m(k, k + a); // copy k to m
    sort(m.begin(), m.end());
    int num = 1;
    int rec[a];
    rec[0] = m[0];
    for (int i = 1; i < a; i++)
    {
        if (m[i] != m[i - 1])
            rec[num++] = m[i];
    }
    for (int i = 0; i < a; i++)
    {
        k[i] = lower_bound(rec, rec + num, k[i]) - rec;
    }
    for (int i = 0; i < a - 1; i++)
    {
        cout << k[i] << " ";
    }
    cout << k[a - 1] << endl;
    return 0;
}