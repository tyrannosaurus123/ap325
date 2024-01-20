#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0)
int arr[100005] = {0};
int boss[100005] = {0};

int rfind(int n)
{
    if (boss[n] < 0)
        return n;
    return boss[n] = rfind(boss[n]);
}
multiset<int> s;
signed main()
{
    io;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            if (arr[i - 1] == 1)
            {
                int boss_index = rfind(i - 1);
                boss[i] = boss_index;
                s.erase(s.find(-boss[boss_index]));
                boss[boss_index]--;
                s.insert(-boss[boss_index]);
            }
            else
            {
                boss[i] = -1;
                s.insert(1);
            }
        }
    }
    int ans_max = s.empty() ? 0 : *(s.rbegin());
    int ans_min = s.empty() ? 0 : *(s.begin());
    for (int i = 0; i < k; i++)
    {
        int index;
        cin >> index;
        arr[index] = 1;
        if (arr[index - 1] == 0 && arr[index + 1] == 0)
        {
            boss[index] = -1;
            s.insert(1);
        }
        else if (arr[index - 1] == 0 && arr[index + 1] == 1)
        {
            int boss_index = rfind(index + 1);
            boss[index] = boss_index;
            s.erase(s.find(-boss[boss_index]));
            boss[boss_index]--;
            s.insert(-boss[boss_index]);
        }
        else if (arr[index - 1] == 1 && arr[index + 1] == 0)
        {
            int boss_index = rfind(index - 1);
            boss[index] = boss_index;
            s.erase(s.find(-boss[boss_index]));
            boss[boss_index]--;
            s.insert(-boss[boss_index]);
        }
        else
        {
            int boss_left = rfind(index - 1);
            int boss_right = rfind(index + 1);
            s.erase(s.find(-boss[boss_left]));
            s.erase(s.find(-boss[boss_right]));
            if (boss[boss_left] < boss[boss_right])
            {
                boss[boss_left] += boss[boss_right] - 1;
                boss[boss_right] = boss_left;
                boss[index] = boss_left;
                s.insert(-boss[boss_left]);
            }
            else
            {
                boss[boss_right] += boss[boss_left] - 1;
                boss[boss_left] = boss_right;
                boss[index] = boss_right;
                s.insert(-boss[boss_right]);
            }
        }
        ans_max += *(s.rbegin());
        ans_min += *(s.begin());
    }
    cout << ans_max << endl << ans_min << endl;
    return 0;
}