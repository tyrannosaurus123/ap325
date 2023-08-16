// 參考 https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define io cin.tie(0), ios::sync_with_stdio(0)
#define x first
#define y second
#define MAX 1e18 + 1
bool cmp(pii s1, pii s2)
{
    if (s1.y == s2.y)
        return s1.x < s2.x;
    return s1.y < s2.y;
}
int rec(pii px[], pii py[], int n)
{
    if (n == 1)
        return MAX;
    else if (n == 2)
        return llabs(px[0].x - px[1].x) + llabs(px[0].y - px[1].y);
    int mid = n / 2, midx = px[mid].x;
    pii pyl[mid], pyr[n-mid];      // pyl store x less than midx and pyr store x greater than midx 
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if(l==mid) pyr[r++]=py[i];
        else if(r==n-mid) pyl[l++]=py[i];
        else if (py[i].x < midx || (py[i].x == midx && py[i].y < py[mid].y))
        {
            pyl[l++] = py[i];
        }
        else{
            pyr[r++]=py[i];
        }
    }
    int d1 = rec(px, pyl, l);
    int d2 = rec(px + mid, pyr, r);
    int minn = min(d1, d2);
    pii check[n];
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (llabs(py[i].x - midx) < minn)
        {
            check[len++] = py[i];
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int dx = llabs(check[i].x - check[j].x);
            int dy = llabs(check[i].y - check[j].y);
            if (dy >= minn)
                break;
            minn = min(dy + dx, minn);
        }
    }
    return minn;
}
signed main()
{
    io;
    int n;
    cin >> n;
    pii pointX[n + 1], pointY[n + 1];
    for (int i = 0; i < n; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;
        pointX[i] = {x1, y1};
        pointY[i] = {x1, y1};
    }
    sort(pointX, pointX + n);
    sort(pointY, pointY + n, cmp);
    cout << rec(pointX, pointY, n) << endl;
    return 0;
}