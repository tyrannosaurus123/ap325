#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io cin.tie(0), ios::sync_with_stdio(0);
const int N = 1e5 + 10;
const int maxn = 1e9 + 10;
queue<int> q;
struct
{
    int c, h;
    int pre, next;
    int alive;
} node[N];

void removable(int i)
{
    if (!node[i].alive)
        return;
    int s = node[i].pre, t = node[i].next;
    if (node[i].c - node[i].h >= node[s].c ||
        node[i].c + node[i].h <= node[t].c)
    {
        q.push(i);
        node[i].alive = 0;
        node[s].next = t;
        node[t].pre = s;
    }
}
signed main()
{
    io 
    int n, r;
    cin >> n >> r;
    int total = 0, high = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].c;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].h;
    }
    node[0].h = maxn;
    node[0].c = 0;
    node[n + 1].h = maxn;
    node[n + 1].c = r;
    for (int i = 1; i <= n; i++)
    {
        node[i].next = i + 1;
        node[i].pre = i - 1;
        node[i].alive = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        removable(i);
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        total++;
        high = max(high, node[t].h);
        removable(node[t].next);
        removable(node[t].pre);
    }
    cout << total << endl << high;
    return 0;
}