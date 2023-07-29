#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);
#define N 100010

signed main()
{
    io 
    int parent[N] = {0};    // parent of node i
    int h[N] = {0};         // height of node i
    int deg[N];             // num of children
    queue<int> Q;
    int n, i, j, ch;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> deg[i];
        if (deg[i] == 0)
            Q.push(i);
        for (j = 0; j < deg[i]; j++)
        {
            cin >> ch;
            parent[ch] = i;
        }
    }
    int root;
    long long total = 0;
    while (1)
    {
        int v = Q.front();
        Q.pop();
        total += h[v];
        int p = parent[v];
        if (p == 0)
        {
            root = v;
            break;
        }
        h[p] = max(h[p], h[v] + 1);
        if (--deg[p] == 0)
            Q.push(p);
    }
    cout << root << endl << total << endl;
    return 0;
}