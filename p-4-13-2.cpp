#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[100001];
int func(int *arr, int left, int right)   // right is open
{ 
    int ans = 0;
    if (right - left == 1)
        return max(ans, arr[left]); // one element
    else if (right - left == 2)     // two elements
    { 
        ans = max(arr[left], arr[right - 1]);
        return max(ans, arr[left] + arr[right - 1]);
    }
    int m = (right + left) / 2;
    int tmp1 = 0, lmax = 0, tmp2 = 0, rmax = 0;
    
    // count max in consecutive union of left and right intervals
    for (int i = m - 1; i >= left; i--)
    { 
        tmp1 += arr[i];
        lmax = max(lmax, tmp1);
    }
    for (int i = m; i < right; i++)
    {
        tmp2 += arr[i];
        rmax = max(rmax, tmp2);
    }
    ans = max(ans, lmax + rmax);
    lmax = func(arr, left, m);
    rmax = func(arr, m, right);
    ans = max(ans, lmax);
    ans = max(ans, rmax);
    return ans;
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << func(arr, 0, n);
    return 0;
}