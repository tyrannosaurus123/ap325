// 參考 https://wky95.github.io/tcircoj-d023/?fbclid=IwAR1VFpVmzFB6gPpuzmIAKjT26vYfotvbSPasCpw_2JOH0Rv9xerInIJQ06k

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, start, w, tmp, *arr, *ans;

int count(int l, int r)
{
    int h = min(arr[l], arr[r]);
    return (r - l) * h;
}

void dfs(int l, int r, int w)
{
    if (w <= count(l, r))
    {
        int height = w / (r - l);
        for (int i = l; i < r; i++)
        {
            ans[i] = height;
        }
    }
    else if (arr[l] < arr[r])
    {
        tmp = l - 1;
        while (arr[tmp] < arr[l])
        {
            tmp--;
        }
        if (w < (r - tmp) * arr[l])
        {
            for (int i = l; i < r; i++)
            {
                ans[i] = arr[l];
            }
            dfs(l - 1, l, w - arr[l] * (r - l));
        }
        else
        {
            dfs(tmp, r, w);
        }
    }
    else
    {
        tmp = r + 1;
        while (arr[tmp] < arr[r])
        {
            tmp++;
        }
        if (w < (tmp - l) * arr[r])
        {
            for (int i = l; i < r; i++)
            {
                ans[i] = arr[r];
            }
            dfs(r, r + 1, w - arr[r] * (r - l));
        }
        else
        {
            dfs(l, tmp, w);
        }
    }
}

signed main()
{
    scanf("%lld%lld%lld", &n, &start, &w);
    arr = (int *)calloc(n, sizeof(int));
    ans = (int *)calloc(n - 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    dfs(start, start + 1, w);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%lld ", ans[i]);
    }
}